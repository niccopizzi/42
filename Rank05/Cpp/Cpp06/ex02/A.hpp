#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base
{
    public:
        A();
        ~A();

        Base*   generate(void);
        void    identify(Base* p);
        void    identify(Base& p);
};


#endif // A.HPP