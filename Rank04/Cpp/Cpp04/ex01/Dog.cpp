#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal()
{
    type = dog.type;
    brain = new Brain(*dog.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
    type = dog.type;
    delete brain;
    brain = new Brain(*dog.brain);
    std::cout << "Dog Copy assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

Brain&  Dog::getBrain() const
{
    return (*brain);
}

void    Dog::makeSound() const
{
    std::cout << "Bark!!" << std::endl;
}