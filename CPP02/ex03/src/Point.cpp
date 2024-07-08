#include "Point.hpp"
#include "utils.hpp"
#include <cmath>

Point::Point() : x(0), y(0), z(0)
{
	// print_message(CTOR_DEFAULT_CALL, GREEN_COLOR);
}
Point::Point(const Fixed x, const Fixed y, const Fixed z) : x(x), y(y), z(z)
{   
	// print_message(CTOR_ARGS_CALL, GREEN_COLOR);

}
Point::~Point()
{
	// print_message(DTOR_DEFAULT_CALL, RED_COLOR);
}

std::ostream &operator<<(std::ostream &out, Point const &value)
{
	out << "Point(" << value.get_x() << ", " << value.get_y() << ", " << value.get_z() << ")";
	return (out);
}

Point::Point(const Point &other)
{
	// print_message(CTOR_COPY_CALL, GREEN_COLOR);
	*this = other;
}
const Fixed Point::get_x() const
{
	return (x);
}

const Fixed Point::get_y() const
{
	return (y);
}

const Fixed Point::get_z() const
{
	return (z);
}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		const_cast<Fixed &>(x) = other.get_x();
		const_cast<Fixed &>(y) = other.get_y();
		const_cast<Fixed &>(z) = other.get_z();
	}
	return (*this);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed x = (b.get_x() - a.get_x()) * (point.get_y() - a.get_y()) - (b.get_y() - a.get_y()) * (point.get_x() - a.get_x());
	Fixed y = (c.get_x() - b.get_x()) * (point.get_y() - b.get_y()) - (c.get_y() - b.get_y()) * (point.get_x() - b.get_x());
	Fixed z = (a.get_x() - c.get_x()) * (point.get_y() - c.get_y()) - (a.get_y() - c.get_y()) * (point.get_x() - c.get_x());

	std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
	if ((x >= 0 && y >= 0 && z >= 0) || (x <= 0 && y <= 0 && z <= 0))
	{
		std::cout << "Point(" << point.get_x() << ", " << point.get_y() << ", " << point.get_z() << ") is inside the triangle" << std::endl;
		return true;
	}
	std::cout << "Point(" << point.get_x() << ", " << point.get_y() << ", " << point.get_z() << ") is not inside the triangle" << std::endl;
	return false;
}
