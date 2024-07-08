#include "fixed.hpp"
#include "utils.hpp"
#include "Point.hpp"

int main()
{

    Point a;
    Point b(1, 2, 3);
    Point c(b);


std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << c << std::endl;
std::cout << std::endl;

bsp(a, b, c, Point(0, 0, 0));
bsp(a, b, c, Point(1, 2, 3));
bsp(a, b, c, Point(1, 2, 4));
bsp(a, b, c, Point(1, 2, 2));
bsp(a, b, c, Point(1, 3, 3)); 
bsp(a, b, c, Point(1, 1, 3));
bsp(a, b, c, Point(1, 2, 2));
bsp(a, b, c, Point(1, 3, 2));
bsp(a, b, c, Point(1, 1, 2));
  return 0;
}