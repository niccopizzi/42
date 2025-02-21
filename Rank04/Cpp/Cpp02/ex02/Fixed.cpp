#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractionalBits = 8;

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
    float     new_value;

    new_value = (value * float(1 << fractionalBits));
    if (value <= 0)
        new_value -= 0.5;
    else
        new_value += 0.5;
    setRawBits(new_value);
   // std::cout << "Float constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
   // std::cout << "Copy constructor called"<<std::endl;
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    //std::cout << "Copy assignment operator called"<<std::endl;
    value = fixed.value;
    return (*this);
}

Fixed::~Fixed()
{
   // std::cout << "Destructor called"<<std::endl;
}

bool    Fixed::operator>(const Fixed& fixed)
{
    return (value > fixed.getRawBits());
}

bool    Fixed::operator<(const Fixed& fixed)
{
    return (value < fixed.getRawBits());
}

bool    Fixed::operator>=(const Fixed& fixed)
{
    return (value >= fixed.getRawBits());
}

bool    Fixed::operator<=(const Fixed& fixed)
{
    return (value <= fixed.getRawBits());
}

bool    Fixed::operator==(const Fixed& fixed)
{
    return (value == fixed.getRawBits());
}

bool    Fixed::operator!=(const Fixed& fixed)
{
    return (value != fixed.getRawBits());
}

Fixed    Fixed::operator+(const Fixed& fixed)
{
    Fixed   newFix;

    newFix.setRawBits(value + fixed.getRawBits());
    return (newFix);
}

Fixed    Fixed::operator-(const Fixed& fixed)
{
    Fixed   newFix;

    newFix.setRawBits(value + fixed.getRawBits());
    return (newFix);
}
    
Fixed    Fixed::operator*(const Fixed& fixed)
{
    Fixed   newFix;
    int     newVal;

    newVal = (((value * fixed.getRawBits()) >> fractionalBits));
    newVal += (newVal >> fractionalBits) & 1;

    newFix.setRawBits(newVal);
    return (newFix);
}

Fixed   Fixed::operator/(const Fixed& fixed)
{
    if (fixed.getRawBits() == 0)
    {
        throw("Error, division by 0");
    }
    return (Fixed((value << fractionalBits) / fixed.getRawBits()));
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

    float       floatVal = ((float)value / (float)(1 << fractionalBits));
    return ((floatVal));
}

int Fixed::toInt(void) const
{
    return (value /( 1 << fractionalBits));
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
    if (fixed1.value >= fixed2.value)
        return (fixed1);
    return (fixed2);
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
    if (fixed1.value >= fixed2.value)
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
    if (fixed1.value <= fixed2.value)
        return (fixed1);
    return (fixed2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    float   fixedVal;

    fixedVal = fixed.toFloat();
    return (os << fixedVal);
}