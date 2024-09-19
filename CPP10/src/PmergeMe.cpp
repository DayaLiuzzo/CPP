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

// void trash()
// {
//     std::vector<int> jacob;
//     jacob = {0, 1, 1, 3, 5, 11, 21};
//     std::vector<int> vec;
//     vec = {6, 20, 52, 1, 3, 53, 9, 27};
// }

// int get_jacob_value(int n, std::vector<int> jacob)
// {
//     size_t i = 0;
//     while(i < jacob.size())
//     {
//         if(jacob[i] >= n)
//             break;
//         i++;
//     }
//     std::cout << "i: " << i << std::endl;
//     std::cout << "jacob[i]: " << jacob[i] << std::endl;
//     return jacob[i];
// }

template<class C_P>
int get_pair_value(std::vector<int> jacob_pair,  C_P &vec_pair)
{
    int value_to_insert = -1;
    int jacob_value = jacob_pair.back();
    value_to_insert = vec_pair[jacob_value].first;
    vec_pair.erase(vec_pair.begin() + jacob_value);
    return value_to_insert;
}

int binarySearchInsert(std::vector<int> &vec, int value, std::vector<int> &jacob)
{
    int n = vec.size();
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

void insertInOrder(std::vector<int> &vec, int value)
{
    int size = vec.size();
    std::vector<int> jacob = generateJacobsthal(size);
    int jacob_index = jacob.back();
    int pos = binarySearchInsert(vec, value, jacob);
    vec.push_back(value);
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

template<class C, class C_P>
void FordJohnson(C &vec, C_P &vec_pair)
{
    std::vector<int> jacob_pair;
    int value_to_insert = -1;
    int top_value = -1;
    int n_p = vec_pair.size();
    
    vec.clear();
    place_all_greater(vec, vec_pair);
            std::cout << "-------------------" << std::endl;
    for (; n_p > 0;){
        jacob_pair = generateJacobsthal(n_p);
        value_to_insert = get_pair_value(jacob_pair, vec_pair);
        // std::cout << "-------------------" << std::endl;
        insertInOrder(vec, value_to_insert);
        n_p = vec_pair.size();
    }
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }
}
void Merge_Insert_Sort(std::vector<int> &vector, vector_pair &vector_pair)
{
    bool isOdd = vector.size() % 2;
    int Odd;

    if(isOdd)
    {
        Odd = vector.back();
        vector.pop_back();
    }
    make_pairs(vector, vector_pair);
    sort_pairs(vector_pair);
    sort_vec_pairs(vector_pair);
    print(vector_pair);
    FordJohnson(vector, vector_pair);

}
void PmergeMe::execute(int ac, char **av)
{
    vector_pair vector_pair;
    deque_pair deque_pair;
    // std::vector<int> const jacob = 123456789;
    if(!init_containers(ac, av))
        return;
    // std::cout << "HERE" << std::endl;   
    Merge_Insert_Sort(this->vector, vector_pair);
}

template <typename RandomAccessIterator, typename Container>
bool isSorted(RandomAccessIterator it, RandomAccessIterator next, Container container)
{
    if (container->empty()) {
        return false;
    }
    ++next;

    while (next != container->end()) {
        if (*it > *next) {
            return false;
        }
        ++it;
        ++next;
    }
    return true;
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

    template <typename RandomAccessIterator>
    bool is_alone(RandomAccessIterator it)
    {
        if(it->first == ODD)
        {
            it->first = it->second;
            it->second = ODD;
            return true;
        }
        else if(it->second == ODD)
            return true;
        return false;
    }
    
