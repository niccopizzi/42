#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
   // std::cout << "Default constructor called"<<std::endl;
    value = 0;
}

Fixed::Fixed(const int value)
{
    //std::cout << "Int constructor called"<<std::endl;
    this->value = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
   // std::cout << "Float constructor called"<<std::endl;
    this->value = (value * float(1 << fractionalBits)) + (value <= 0 ? -1 : 1);
}

Fixed::Fixed(const Fixed& fixed)
{
   // std::cout << "Copy constructor called"<<std::endl;
    this->value = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    //std::cout << "Copy assignment operator called"<<std::endl;
    value = fixed.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
   // std::cout << "Destructor called"<<std::endl;
}

bool    Fixed::operator>(const Fixed& fixed) const
{
    return (value > fixed.getRawBits());
}

bool    Fixed::operator<(const Fixed& fixed) const
{
    return (value < fixed.getRawBits());
}

bool    Fixed::operator>=(const Fixed& fixed) const
{
    return (value >= fixed.getRawBits());
}

bool    Fixed::operator<=(const Fixed& fixed) const
{
    return (value <= fixed.getRawBits());
}

bool    Fixed::operator==(const Fixed& fixed) const
{
    return (value == fixed.getRawBits());
}

bool    Fixed::operator!=(const Fixed& fixed) const
{
    return (value != fixed.getRawBits());
}

Fixed    Fixed::operator+(const Fixed& fixed) const
{
    Fixed   newFix;

    newFix.setRawBits(value + fixed.getRawBits());
    return (newFix);
}

Fixed    Fixed::operator-(const Fixed& fixed) const
{
    Fixed   newFix;

    newFix.setRawBits(value - fixed.getRawBits());
    return (newFix);
}

Fixed    Fixed::operator-(void) const
{
    Fixed   newFix;

    newFix.setRawBits(-value);
    return (newFix);
}
    
Fixed    Fixed::operator*(const Fixed& fixed) const
{
    Fixed   newFixed;

    newFixed.setRawBits((value * fixed.getRawBits()) >> fractionalBits);
    return (newFixed);
}

Fixed   Fixed::operator/(const Fixed& fixed) const
{
    Fixed   newFixed;

    if (fixed.getRawBits() == 0)
    {
        throw("Error, division by 0");
    }
    newFixed.setRawBits((value << fractionalBits) / fixed.getRawBits());
    return (newFixed);
}

Fixed    Fixed::operator++()
{
    this->value += 1 + std::numeric_limits<float>::epsilon();
    return (*this);
}

Fixed     Fixed::operator++(int dummyVar)
{
    Fixed temp = *this;
    (void)dummyVar;
    this->value += 1 + std::numeric_limits<float>::epsilon();
    return (temp);
}

Fixed     Fixed::operator--()
{
    this->value -= 1 + std::numeric_limits<float>::epsilon();
    return (*this);
}

Fixed     Fixed::operator--(int dummyVar)
{
    Fixed temp = *this;
    (void)dummyVar;
    this->value -= 1 + std::numeric_limits<float>::epsilon();
    return (temp);
}

int Fixed::getRawBits() const
{
    //std::cout << "getRawBits member function called"<<std::endl;
    return (value);
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

void    Fixed::printBits(void) const
{
     for (int i = 31; i >=0 ; i--)
    {
        if (value >> (i) & 1)
            std::cout << 1;
        else
            std::cout << 0;
    }
    std::cout << std::endl;
}

float Fixed::toFloat(void) const
{
    return((float)value / (float)(1 << fractionalBits));
}

int Fixed::toInt(void) const
{
    return (value / (1 << fractionalBits));
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1.value >= fixed2.value)
        return (fixed1);
    return (fixed2);
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1 >= fixed2)
        return (fixed1);
    return (fixed2);
}
 
Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1.value <= fixed2.value)
        return (fixed1);
    return (fixed2);
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1 <= fixed2)
        return (fixed1);
    return (fixed2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    return (os << fixed.toFloat());
}