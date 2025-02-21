#include "Point.hpp"

Point::Point() : x(0), y(0)
{
   // std::cout << "Default constructor called\n";
}

Point::Point(const float n1, const float n2) : x(n1), y(n2)
{
  //  std::cout << "Floating arguments constructor called\n";
}

Point::~Point()
{
   // std::cout << "Point destructor called\n";
}

Point::Point(const Point& point) : x(point.x.getRawBits()), y(point.y.getRawBits())
{
  //  std::cout << "Copy constructor called\n";
}

const Fixed&  Point::getX() const
{   
    return (x);
}

const Fixed&  Point::getY() const
{   
    return (y);
}

bool        Point::operator==(const Point& point)
{
    return(x.getRawBits() == point.getX().getRawBits() 
            && y.getRawBits() == point.getY().getRawBits());
}

bool        Point::operator==(Point& point)
{
    return(x.getRawBits() == point.getX().getRawBits() 
            && y.getRawBits() == point.getY().getRawBits());
}

bool        Point::operator!=(const Point& point)
{
    return (x.getRawBits() != point.getX().getRawBits() 
            && y.getRawBits() != point.getY().getRawBits());
}

bool        Point::operator!=(Point& point)
{
    return (x.getRawBits() != point.getX().getRawBits() 
            && y.getRawBits() != point.getY().getRawBits());
}

int         Point::getXBits() const
{
    return (x.getRawBits());
}

int         Point::getYBits() const
{
    return (y.getRawBits());
}