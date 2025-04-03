#include "Cat.hpp"

Cat::Cat(void) : Animal()
{  
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal()
{
    this->type = cat.getType(); 
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
    this->type = cat.getType();
    std::cout << "Cat Copy assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Meow!!" << std::endl;
}