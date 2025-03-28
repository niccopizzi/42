#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point 
{
private:
    const Fixed x;
    const Fixed y;
    void operator=(const Point& p);

public:
    Point();
    Point(const float xVal, const float yVal);
    Point(const int rawValX, const int rawValY);
    Point(const Point& p);
    Point(const Fixed& x, const Fixed& y);
    ~Point();

    const Fixed& getX(void) const;
    const Fixed& getY(void) const;

    Point operator+(const Point& p) const;
    Point operator-(const Point& p) const;
};

std::ostream& operator<<(std::ostream& os, const Point& p);

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP