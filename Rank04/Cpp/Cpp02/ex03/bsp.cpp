#include "Point.hpp"

Fixed calculateArea(const Point& p1, const Point& p2, const Point& p3)
{
    Fixed term1 = p1.getX() * (p2.getY() - p3.getY());
    Fixed term2 = p2.getX() * (p3.getY() - p1.getY());
    Fixed term3 = p3.getX() * (p1.getY() - p2.getY());

    Fixed area = (term1 + term2 + term3) / 2;

    if (area < 0)
        area = area * -1;

    std::cout << "Term1: " << term1 << ", Term2: " << term2 << ", Term3: " << term3 << std::endl;
    std::cout << "Raw area before abs: " << (term1 + term2 + term3) / 2 << std::endl;
    std::cout << "Final area: " << area << std::endl;

    return area;
}


bool    bsp(Point const a, Point const b, Point const c, Point const point)
{

    if (&point == &a || &point == &b || &point == &c)
        return (false);   
    calculateArea(a,b,c);
    return (true);
}