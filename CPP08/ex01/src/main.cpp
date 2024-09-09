#include "Span.hpp"
#include "utils.hpp"

#define VECTOR_SIZE 3000
#define VEC_SMALL_SIZE 5
#define VEC_SIZE 10000
int main()
{

    {
    try
    {
    Span sp = Span(VEC_SMALL_SIZE);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
         std::cerr << RED_COLOR<< e.what() << RESET_COLOR << std::endl;
    }
    }
    std::cout << "----------------" << std::endl;
    std::cout << "Overflowing size limit" << std::endl;
    {
    try
    {   
        Span sp = Span(VEC_SMALL_SIZE);
        sp.addNumber(17);
        sp.addNumber(16);
        sp.addNumber(15);
        sp.addNumber(14);
        sp.addNumber(13);
        sp.display_data();
        sp.addNumber(12);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED_COLOR<< e.what() << RESET_COLOR << std::endl;
    }
    }
    std::cout << "----------------" << std::endl;
    std::cout << "Adding numbers from a vector" << std::endl;
    {
    try
    {
        Span sp(VEC_SMALL_SIZE);
        int random;
        std::vector<int> v;
        for (int i = 0; i < VEC_SMALL_SIZE; i++)
        {
            random = getRandomNumber(1, 1000);
            v.push_back(random);
        }
        for (int i = 0; i < VEC_SMALL_SIZE; i++)
        {
            std::cout << "v[" << i << "]: " << v[i] << std::endl;
        }
        sp.addNumbers(v.begin(), v.end());
        sp.display_data();
            std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED_COLOR<< e.what() << RESET_COLOR << std::endl;
    }
    }
    std::cout << "----------------" << std::endl;
    std::cout << "Adding too much numbers from a vector" << std::endl;
    {
    try
    {
        Span sp(VEC_SMALL_SIZE);
        int random;
        std::vector<int> v;
        for (int i = 0; i < VEC_SMALL_SIZE + 3; i++)
        {
            random = getRandomNumber(1, 1000);
            v.push_back(random);
        }
        for (int i = 0; i < VEC_SMALL_SIZE + 3; i++)
        {
            std::cout << "v[" << i << "]: " << v[i] << std::endl;
        }
        sp.addNumbers(v.begin(), v.end());
        sp.display_data();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED_COLOR<< e.what() << RESET_COLOR << std::endl;
    }
    }
    std::cout << "----------------" << std::endl;
    std::cout << "Deep copy check" << std::endl;
    {
    try
    {
        Span sp = Span(VEC_SMALL_SIZE);
        sp.addNumber(17);
        sp.addNumber(16);
        sp.addNumber(15);
        sp.addNumber(14);
        std::cout << "SP :" << std::endl;
        sp.display_data();
        Span sp2 = sp;
        std::cout << "SP2 :" << std::endl;
        sp2.display_data();
        sp.addNumber(13);
        sp2.addNumber(12);
        std::cout << "SP :" << std::endl;
        sp.display_data();
        std::cout << "SP2 :" << std::endl;
        sp2.display_data();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED_COLOR<< e.what() << RESET_COLOR << std::endl;
    }
    }
        std::cout << "----------------" << std::endl;
    std::cout << "Deep copy check" << std::endl;
    {
    try
    {
        Span sp = Span(VEC_SMALL_SIZE);
        sp.addNumber(17);
        sp.addNumber(16);
        sp.addNumber(15);
        sp.addNumber(14);
        std::cout << "SP :" << std::endl;
        sp.display_data();
        Span sp2(sp);
        std::cout << "SP2 :" << std::endl;
        sp2.display_data();
        sp.addNumber(13);
        sp2.addNumber(12);
        std::cout << "SP :" << std::endl;
        sp.display_data();
        std::cout << "SP2 :" << std::endl;
        sp2.display_data();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED_COLOR<< e.what() << RESET_COLOR << std::endl;
    }
    }
    // std::cout << "----------------" << std::endl;
    // std::cout << "Adding LOTS OF numbers from a vector" << std::endl;
    // {
    // try
    // {
    //     Span sp(VEC_SIZE);
    //     int random;
    //     std::vector<int> v;
    //     for (int i = 0; i < VEC_SIZE; i++)
    //     {
    //         random = getRandomNumber(1, 1000);
    //         v.push_back(random);
    //     }
    //     for (int i = 0; i < VEC_SIZE; i++)
    //     {
    //         std::cout << "v[" << i << "]: " << v[i] << std::endl;
    //     }
    //     sp.addNumbers(v.begin(), v.end());
    //     sp.display_data();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << RED_COLOR<< e.what() << RESET_COLOR << std::endl;
    // }
    // }
    // std::cout << "----------------" << std::endl;
    // std::cout << "Adding too much numbers from a vector" << std::endl;
    // {
    // try
    // {
    //     Span sp(VEC_SIZE);
    //     int random;
    //     std::vector<int> v;
    //     for (int i = 0; i < VEC_SIZE + 3; i++)
    //     {
    //         random = getRandomNumber(1, 1000);
    //         v.push_back(random);
    //     }
    //     for (int i = 0; i < VEC_SIZE + 3; i++)
    //     {
    //         std::cout << "v[" << i << "]: " << v[i] << std::endl;
    //     }
    //     sp.addNumbers(v.begin(), v.end());
    //     sp.display_data();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << RED_COLOR<< e.what() << RESET_COLOR << std::endl;
    // }
    // }
    
    std::cout << "----------------" << std::endl;
    std::cout << "Adding LOTS OF numbers from a vector" << std::endl;
    {
    try
    {
        Span sp(VEC_SIZE);
        int random;
        std::vector<int> v;
        for (int i = 0; i < VEC_SIZE; i++)
        {
            random = getRandomNumber(1, 1000);
            v.push_back(random);
        }
        sp.addNumbers(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED_COLOR<< e.what() << RESET_COLOR << std::endl;
    }
    }
    std::cout << "----------------" << std::endl;
    std::cout << "Adding too much numbers from a vector" << std::endl;
    {
    try
    {
        Span sp(VEC_SIZE);
        int random;
        std::vector<int> v;
        for (int i = 0; i < VEC_SIZE + 3; i++)
        {
            random = getRandomNumber(1, 1000);
            v.push_back(random);
        }
        sp.addNumbers(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED_COLOR<< e.what() << RESET_COLOR << std::endl;
    }
    }
    
    // return 0;

}

int getRandomNumber(int min, int max) {
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(0)));
        seeded = true;
    }
    return min + rand() % ((max - min) + 1);
}