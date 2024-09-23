#include "PmergeMe.hpp"


PmergeMe::PmergeMe()
{
    return;
}

PmergeMe::PmergeMe(PmergeMe const &cpy)
{
    *this = cpy;
    return;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &cpy)
{
    this->vector = cpy.vector;
    this->deque = cpy.deque;
    this->strings = cpy.strings;
    return *this;
}

PmergeMe::~PmergeMe()
{
    return;
}
template <typename Container>
void print(Container container) {
    for (typename Container::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
}


bool error_msg(std::string const &msg)
{
    std::cerr << RED_COLOR << msg << RESET_COLOR << std::endl;
    return false;
}


bool isValidInt(const std::string& str)
{
    if(str.empty())
        return false;
    
    std::stringstream ss(str);
    int value;
    char remainingChar;

    if(!(ss >> value) || ss.get(remainingChar))
        return false;
    if(value < 0 || value > std::numeric_limits<int>::max())
        return false;
    return true;
}

bool parse_string(const std::string& input)
{
    std::stringstream ss(input);
    std::string token;
    int i = 0;
    while(ss >> token)
    {
        i++;
        if(!isValidInt(token))
            return false;
    }
    if(i == 0)
        return false;
    return true;
}

bool PmergeMe::init_containers(int ac, char **av)
{
    if(ac < 3)
        return error_msg("Usage: ./pmerge [positive integers]");
    for(int i = 1; i < ac; i++)
    {
        strings.push_back(av[i]);
    }
    for(std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
    {
        if(!parse_string(*it))
            return error_msg("Usage: ./pmerge [positive integers]");
        deque.push_back(std::atoi(it->c_str()));
    }
    this->vector.assign(this->deque.begin(), this->deque.end());
    if(has_duplicates())
        return error_msg("has duplicates");
    return true;
}

template <typename T, typename T_P>
void make_pairs(T &vec, T_P &vec_pair)
{
    for (typename T::iterator it = vec.begin(); it != vec.end(); it++)
    {
        std::pair<int, int> pair(*it , *(++it));
        vec_pair.push_back(pair);
    }
    return ;
}

template <typename T_P>
void sort_pairs(T_P &vec_pair)
{
    for(typename T_P::iterator it = vec_pair.begin(); it != vec_pair.end(); it++)
    {
        if (it->first > it->second)
        {
            std::swap(it->first,it->second);
        }
    }
    return ;
}
template <typename T_P>
void sort_vec_pairs(T_P &vec_pair)
{
    if (vec_pair.size() <= 1)
        return;
   typename T_P::iterator mid = vec_pair.begin() + (vec_pair.size() / 2);
    
    T_P left(vec_pair.begin(), mid);
    T_P right(mid, vec_pair.end());
    sort_vec_pairs(left);
    sort_vec_pairs(right);
    
   typename T_P::iterator l = left.begin();
   typename T_P::iterator r = right.begin();
    int i = 0;
    while (l != left.end() && r != right.end())
    {
        if (l->second < r->second)
        {
            vec_pair[i] = *l;
            l++;
        }
        else
        {
            vec_pair[i] = *r;
            r++;
        }
        i++;
    }
    while(l != left.end())
    {
        vec_pair[i++] = *l++;
    }
    while(r != right.end())
    {
        vec_pair[i++] = *r++;
    }
}
template <class C, class C_P>
void place_all_greater(C &vec, C_P const &vec_pair)
{
    for(typename C_P::const_iterator it = vec_pair.begin(); it != vec_pair.end(); it++)
    {
        vec.push_back(it->second);
    }
}

template<class C_P>
std::pair<int, int> get_pair_value(std::vector<int> jacob_pair,  C_P &vec_pair)
{
    std::pair<int, int> value_to_insert;
    int jacob_value = jacob_pair.back();
    value_to_insert = std::make_pair(vec_pair[jacob_value].first, vec_pair[jacob_value].second); 
    vec_pair.erase(vec_pair.begin() + jacob_value);
    return value_to_insert;
}

template<class C>
int findInVector(C& vec, int X) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == X) {
            return i; 
        }
    }
    return vec.size();
}


template<class C>
int binarySearchInsert(C &vec, std::pair<int, int> pair_value, std::vector<int> &jacob)
{
    int value = pair_value.first;
    // int n = vec.size();
    int n = findInVector(vec, pair_value.second);
    int jcb = jacob.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while(low <= high)
    {
        jcb--;
        if(jcb < 0)
            mid = low;
        else
            mid = low + jacob[jcb];
        if (mid >= n)
            mid = n - 1;
        if (vec[mid] == value)
            return (mid);
        else if(vec[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return(low);
}

std::vector<int> generateJacobsthal(int n) 
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    

    if(n == 1)
    {
        jacobsthal.pop_back();
        return jacobsthal;
    }
    while (jacobsthal.back() < n) {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next >= n) break;
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

template<class C>
void insertInOrder(C &vec, std::pair<int, int> value)
{
    int size = vec.size();
    std::vector<int> jacob = generateJacobsthal(size);
    int pos = binarySearchInsert(vec, value, jacob);
    vec.insert(vec.begin() + pos, value.first);
}
template<class C, class C_P>
void FordJohnson(C &vec, C_P &vec_pair)
{
    std::vector<int> jacob_pair;
    std::pair<int, int> value_to_insert;
    int n_p = vec_pair.size();
    
    vec.clear();
    place_all_greater(vec, vec_pair);
    for (; n_p > 0;){
        jacob_pair = generateJacobsthal(n_p);
        value_to_insert = get_pair_value(jacob_pair, vec_pair);
        insertInOrder(vec, value_to_insert);
        n_p = vec_pair.size();
    }
}
template<class C>
void print_container(C vec, bool started)
{
    if(!started)
        std::cout << "Before start: ";
    else
        std::cout << "After start: ";
    for(typename C::iterator it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
template<class C, class C_P>
void Merge_Insert_Sort(C &vector, C_P &vector_pair)
{
    bool isOdd = vector.size() % 2;
    std::pair<int, int> Odd;

    if(isOdd)
    {
        Odd.first = vector.back();
        Odd.second = ODD;
        vector.pop_back();
    }
    make_pairs(vector, vector_pair);
    sort_pairs(vector_pair);
    sort_vec_pairs(vector_pair);
    
    FordJohnson(vector, vector_pair);
    if(isOdd)
        insertInOrder(vector, Odd);
}

void print_time(clock_t start, clock_t end, std::string const &cont, int size)
{
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    
    std::cout << "Time to process a range of " << size << " elements with std::" << cont  << ": " << std::fixed 
         << time_taken;
    std::cout << " sec " << std::endl;
}

void PmergeMe::execute(int ac, char **av)
{
    vector_pair vector_pair;
    deque_pair deque_pair;
    if(!init_containers(ac, av))
        return; 
    print_container(this->vector, false);

    clock_t start = clock();
    Merge_Insert_Sort(this->vector, vector_pair);
    clock_t end = clock();
    print_container(this->vector, true);
    print_time(start, end, "vector", this->vector.size());
    start = clock();
    Merge_Insert_Sort(this->deque, deque_pair);
    end = clock();
    print_time(start, end, "deque", this->deque.size());
}

bool PmergeMe::has_duplicates() {
    std::set<int> seen;
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it) {
        if (seen.find(*it) != seen.end()) {
            return true;
        }
        seen.insert(*it);
    }
    return false; 
}
