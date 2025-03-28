#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called"<<std::endl;
    value = 0;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called"<<std::endl;
    if (value >= (1 << 24))
        std::cout << "Warning, integer values overflows\n";
    this->value = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    this->value = (value * float(1 << fractionalBits)) + (value <= 0 ? -1 : 1);
    std::cout << "Float constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called"<<std::endl;
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called"<<std::endl;
    value = fixed.value;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called"<<std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called"<<std::endl;
    return (value);
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat(void) const
{
    float   ret;

    ret = float(value) / float(1 << fractionalBits);
    return (ret);
}

int Fixed::toInt(void) const
{
    return (value / (1 << fractionalBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    return (os << fixed.toFloat());
}