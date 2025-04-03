#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>


class Animal
{
    protected:
        std::string type;
    public:
        Animal(void); /*Default constructor*/
        Animal(const Animal& ); /*Default copy constructor*/
        Animal& operator=(const Animal& ); /*Default copy assignment operator*/
        virtual ~Animal(void); /*Default destructor*/

        std::string    getType() const;
        virtual void    makeSound() const = 0;
};

#endif //ANIMAL_HPP