#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal(); /*Default constructor*/
        WrongAnimal(const WrongAnimal& ); /*Default copy constructor*/
        WrongAnimal& operator=(const WrongAnimal& ); /*Default copy assignment operator*/
        virtual ~WrongAnimal(void); /*Default destructor*/

        virtual void makeSound() const;

        std::string  getType() const;
};

#endif