#include "Point.hpp"

int main(void)
{
    Point c(3.3f, 1.4f);
    Point b(10.f, 5.2f);
    Point a(2.f, 2.f);

    Point d(0.2f, -0.5f);
        
    if (bsp(a, b, c, d))
        std::cout << "Point is inside\n";
    else
        std::cout << "Point is outside\n";
    return (0);
}