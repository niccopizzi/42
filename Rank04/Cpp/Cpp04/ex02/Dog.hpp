#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain*  brain;
    public:
        Dog(); /*Default constructor*/
        Dog(const Dog& ); /*Default copy constructor*/
        Dog& operator=(const Dog& ); /*Default copy assignment operator*/
        ~Dog(); /*Default destructor*/

        void    makeSound() const;
        Brain& getBrain() const;
};

#endif // DOG.HPP