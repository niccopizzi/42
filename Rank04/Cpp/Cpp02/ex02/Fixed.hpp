#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <limits>

class Fixed
{
private:
    int              value;
    static const int fractionalBits = 8;
public:

    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& fixed);
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();

    bool        operator>(const Fixed& fixed) const;
    bool        operator<(const Fixed& fixed) const;
    bool        operator>=(const Fixed& fixed) const;
    bool        operator<=(const Fixed& fixed) const;
    bool        operator==(const Fixed& fixed) const;
    bool        operator!=(const Fixed& fixed) const;
    Fixed       operator+(const Fixed& fixed) const;
    Fixed       operator-(const Fixed& fixed) const;
    Fixed       operator-(void) const;
    Fixed       operator*(const Fixed& fixed) const;
    Fixed       operator/(const Fixed& fixed) const;
    Fixed       operator++();
    Fixed       operator++(int dummyVar);
    Fixed       operator--();
    Fixed       operator--(int dummyVar);

    int         getRawBits(void) const;
    void        setRawBits(int const raw);
    float       toFloat(void) const;
    int         toInt(void) const;
    void        printBits(void) const;

    static  Fixed& max(Fixed& fixed1, Fixed& fixed2);
    const static  Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
    static  Fixed& min(Fixed& fixed1, Fixed& fixed2);
    const static  Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif