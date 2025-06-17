#include <iostream>
#include "Bureaucrat.hpp"


int main ()
{
    try
    {
        Bureaucrat b("Nino", 0);
        std::cout << b;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat a("MegaDirectorIntergalactic", 1);
        std::cout << a;
        a.promote();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat fan("Fantozzi", 150);
        std::cout << fan;
        fan.downgrade();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}