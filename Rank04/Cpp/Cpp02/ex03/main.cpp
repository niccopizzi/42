#include "Point.hpp"

int main(void)
{
    Point a;

    Point b((float)2.5, (float)1.1);
    Point c((float)1.1, (float)2.2);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    Point   point((float)0.3,(float)0.5);
    if (bsp(a, b ,c, point))
        std::cout << "Point is inside the triangle\n";
    else    
        std::cout << "Point is outside the triangle\n";
    return (0);
}