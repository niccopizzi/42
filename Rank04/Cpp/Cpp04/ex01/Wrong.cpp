#include "Wrong.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "Wrong Animal";
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongA)
{
    this->type = wrongA.getType();
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongA)
{
    this->type = wrongA.getType();
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

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "Wrong Cat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrong) : WrongAnimal()
{
    this->type = wrong.getType();
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrong)
{
    this->type = wrong.getType();
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << "Bark?!" << std::endl;
}

