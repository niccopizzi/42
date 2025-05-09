#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong Animal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongA) : type(wrongA.type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongA)
{
    type = wrongA.type;
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "Wrong sound" << std::endl;
}

std::string     WrongAnimal::getType() const
{
    return (type);
}
