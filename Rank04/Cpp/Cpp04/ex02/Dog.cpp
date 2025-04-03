#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    this->type = "Dog";
    brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal()
{
    this->type = dog.getType();
    this->brain = new Brain(dog.getBrain());
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
    this->type = dog.getType();
    this->brain = &dog.getBrain();
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