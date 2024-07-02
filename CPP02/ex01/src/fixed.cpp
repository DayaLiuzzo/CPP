#include "fixed.hpp"
#include "utils.hpp"
#include <cmath>


Fixed &Fixed::operator=(const Fixed &other)
{
    print_message(COPY_ASSING_CALL, LILAC_COLOR);
	if (this != &other)
	{
		setRawBits(other.getRawBits());
	}
	return (*this);
}
Fixed::Fixed()
{
	print_message(CTOR_DEFAULT_CALL, GREEN_COLOR);
	setRawBits(0);
}
Fixed::Fixed(const Fixed &other)
{
    print_message(CTOR_COPY_CALL, GREEN_COLOR);
	*this = other;
}
Fixed::~Fixed()
{
	print_message(DTOR_DEFAULT_CALL, RED_COLOR);
}
void Fixed::setRawBits(int const raw)
{
	nb_value = raw;
}

int Fixed::getRawBits(void) const
{
	return (nb_value);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(nb_value) / (1 << nb_frac_bits));
}

int Fixed::toInt(void) const
{
	return (nb_value >> nb_frac_bits);
}

Fixed::Fixed(const int value)
{
    print_message(INT_CTOR_CALL, GREEN_COLOR);
    nb_value = value << nb_frac_bits;
}
Fixed::Fixed(const float value)
{
    print_message(FLOAT_CTOR_CALL, GREEN_COLOR);
    nb_value = static_cast<int>(roundf(value * (1 << nb_frac_bits)));
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    return (out);
} 