#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    Fixed   const x;
    Fixed   const y;
    Point& operator=(const Point& point);

public:

    Point();
    Point(const float n1, const float n2);
    Point(const Point& point);

    const Fixed&        getX() const;
    const Fixed&        getY() const;
    int         getXBits() const;
    int         getYBits() const;
    bool        operator==(Point& point);
    bool        operator==(const Point& point);
    bool        operator!=(Point& point);
    bool        operator!=(const Point& point);
    ~Point();
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif