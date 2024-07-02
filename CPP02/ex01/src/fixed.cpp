#include "fixed.hpp"
#include "utils.hpp"

Fixed::Fixed()
{
    print_message(CTOR_DEFAULT_CALL, GREEN_COLOR);
    setRawBits(0);
}
Fixed::Fixed(const Fixed &other)
{
    print_message(CTOR_COPY_CALL, GREEN_COLOR);
    nb_value = other.getRawBits();
}
Fixed::~Fixed()
{
    print_message(DTOR_DEFAULT_CALL, RED_COLOR);
}
void Fixed::setRawBits( int const raw )
{
    nb_value = raw;
}

int Fixed::getRawBits(void) const
{
    print_message("getRawBits " MEMBER_FUNC_CALL, LILAC_COLOR);
    return (nb_value);
}
Fixed& Fixed::operator=(const Fixed &other) 
{
    print_message(COPY_ASSING_CALL, YELLOW_COLOR);
    if (this != &other) 
    {
        setRawBits(other.getRawBits());
    }
    return *this;
}