#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

C::C()
{
    std::cout << "C constructor called" << std::endl;
}

C::~C()
{
    std::cout << "C destructor called" << std::endl;
}

Base*   C::generate()
{
    int ran;   

    ran = rand() % 3;
    switch (ran)
    {
    case 0:
        return new A;
    case 1:
        return new B;
    case 2:
        return new C;
    default:
        break;
    }
    return (new Base);
}

void    C::identify(Base* p)
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