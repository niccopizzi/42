#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class A;
class B;

class C : public Base
{
    public:
        C();
        ~C();

        Base*   generate(void);
        void    identify(Base* p);
        void    identify(Base& p);
};


#endif // C.HPP