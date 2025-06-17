#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

A::A()
{
    std::cout << "A constructor called" << std::endl;
}

A::~A()
{
    std::cout << "A destructor called" << std::endl;
}

Base*   A::generate()
{
    int ran;   

    ran = rand() % 3;
    switch (ran)
    {
    case 0:
    {
        std::cout << "Generated a new A\n";
        return new A;
    }
    case 1:
    {
        std::cout << "Generated a new B\n";
        return new B;
    }
    case 2:
    {
        std::cout << "Generated a new C\n";
        return new C;
    }
    default:
        break;
    }
    return (new Base);
}

void    A::identify(Base* p)
{
    A* ptrA = dynamic_cast<A*>(p);
    if (ptrA != NULL)
    {
        std::cout << "A\n";
        return;
    }
    B* ptrB = dynamic_cast<B*>(p);
    if (ptrB != NULL)
    {
        std::cout << "B\n";
        return;
    }
    C* ptrC = dynamic_cast<C*>(p);
    if (ptrC != NULL)
    {
        std::cout << "C\n";
        return;
    }
}

void    A::identify(Base& p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A\n";
    }
    catch(const std::exception& e)
    {
        try
        {
            dynamic_cast<B&>(p);
            std::cout << "B\n";
        }
        catch(const std::exception& e)
        {
            std::cout << "C\n";
        }
    }
}