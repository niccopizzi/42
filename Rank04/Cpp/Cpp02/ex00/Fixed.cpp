#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    value = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called\n";
    value = fixed.getRawBits(); 
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called\n";
    value = fixed.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}


int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return (value);
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}