#include "Animal.hpp"

Animal::Animal(void)
{
    type = "Base animal";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& animal)
{
    this->type = animal.type;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& animal)
{
    this->type = animal.type;
    std::cout << "Animal Copy assignment operator called" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void    Animal::makeSound(void) const 
{
    std::cout << "Ehm... something??" << std::endl;   
}

std::string Animal::getType(void) const
{
    return (type);
}

