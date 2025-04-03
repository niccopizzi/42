#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    private:

    public:
        Dog(); /*Default constructor*/
        Dog(const Dog& ); /*Default copy constructor*/
        Dog& operator=(const Dog& ); /*Default copy assignment operator*/
        ~Dog(); /*Default destructor*/

        void    makeSound() const;
};

#endif // DOG.HPP