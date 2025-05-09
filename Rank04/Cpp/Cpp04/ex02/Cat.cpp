#include "Cat.hpp"

Cat::Cat(void) : Animal()
{  
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal()
{
    brain = new Brain(*cat.brain);
    type = cat.type; 
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
    type = cat.type;
    delete brain;
    brain = new Brain(*cat.brain);
    std::cout << "Cat Copy assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Meow!!" << std::endl;
}