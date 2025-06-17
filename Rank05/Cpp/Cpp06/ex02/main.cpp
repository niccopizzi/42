#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    srand(time(0));

    A       theA;
    C       theC;

    Base*   p = theA.generate();

    theA.identify(p);
    theA.identify(theA);
    delete p;
}