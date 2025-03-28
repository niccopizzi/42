#include "Point.hpp"

Point::Point(void) : x(0) , y(0)
{
   // std::cout << "Default constructor called\n";
}

Point::Point(const int rawValX, const int rawValY) : x(rawValX), y(rawValY)
{
   // std::cout << "Raw val constructor called\n";
}

Point::Point(const float xVal, const float yVal) : x(xVal) , y(yVal)
{
   // std::cout << "Float constructor called\n";
}

Point::Point(const Fixed& px, const Fixed& py) : x(px), y(py)
{

}

Point::Point(const Point& p) : x(p.getX()) , y(p.getY())
{
   // std::cout << "Copy constructor called\n";
}
Point::~Point()
{
   // std::cout << "Destructor called\n";
}

void Point::operator=(const Point& p)
{
    (void)p;
    std::cout << "Operator not usable\n";
}

Point Point::operator+(const Point& p) const
{
    return (Point (x.getRawBits() + p.getX().getRawBits(), 
            y.getRawBits() + p.getY().getRawBits()));
}

Point Point::operator-(const Point& p) const
{
    Fixed   newX;
    Fixed   newY;
    newX.setRawBits(x.getRawBits() - p.getX().getRawBits());
    newY.setRawBits(y.getRawBits() - p.getY().getRawBits());

    return (Point(newX, newY));
}

const Fixed& Point::getX(void) const
{
    return (x);
}

const Fixed& Point::getY(void) const
{
    return (y);
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    return (os << "(" << p.getX() << ", " << p.getY() << ")");
}