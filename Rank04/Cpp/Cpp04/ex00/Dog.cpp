#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal()
{
    this->type = dog.getType();
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
    this->type = dog.getType();
    std::cout << "Dog Copy assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Bark!!" << std::endl;
}