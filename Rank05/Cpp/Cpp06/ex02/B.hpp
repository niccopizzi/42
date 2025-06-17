#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base
{
    public:
        B();
        ~B();

        Base*   generate(void);
        void    identify(Base* p);
        void    identify(Base& p);
};

#endif // B.HPP