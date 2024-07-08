#ifndef POINT_HPP
# define POINT_HPP

# include "fixed.hpp"
# include <iostream>

class Point
{
  private:
	const Fixed x;
	const Fixed y;
	const Fixed z;

  public:
	// constructors and destructor
	Point();
	~Point();
    Point(const Fixed x, const Fixed y, const Fixed z);
    Point(const Point &other);

    Point &operator=(const Point &other);

	// member functions
    const Fixed get_x() const;
    const Fixed get_y() const;
    const Fixed get_z() const;
};

bool bsp(const Point a, const Point b, const Point c, const Point point);
std::ostream &operator<<(std::ostream &out, Point const &value);

#endif