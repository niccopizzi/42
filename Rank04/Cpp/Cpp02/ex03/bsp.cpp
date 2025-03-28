#include "Point.hpp"

const Fixed   crossProduct(const Point a, const Point b)
{
    const Fixed   ret = a.getX() * b.getY() - a.getY() * b.getX();
    return (ret);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed   c1 = crossProduct((a - b), (a - point));
    Fixed   c2 = crossProduct((b - c), (b - point));
    Fixed   c3 = crossProduct((c - a), (c - point));

    std::cout << "The c are are:\nc1) " << c1 << "\nc2) " << c2 << "\nc3) " << c3 << "\n";
    return ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0));
}