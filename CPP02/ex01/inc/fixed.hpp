#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

#define CTOR_DEFAULT_CALL "Default Constructor called"
#define CTOR_COPY_CALL "Copy Constructor called"
#define DTOR_DEFAULT_CALL "Default Destructor called"
#define MEMBER_FUNC_CALL "Member Function called"
#define COPY_ASSING_CALL "Copy Assignment Operator called"

class Fixed
{
  private:
    int nb_value;
    static const int nb_frac_bits = 8;

  public:
	Fixed();
	~Fixed();
    Fixed(const Fixed &other);
    Fixed& operator=(const Fixed &other);
    int getRawBits(void) const;
    void setRawBits( int const raw );
};

#endif