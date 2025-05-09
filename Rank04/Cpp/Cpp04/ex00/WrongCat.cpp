#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "Wrong Cat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrong) : WrongAnimal()
{
    type = wrong.type;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrong)
{
    type = wrong.type;
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << "Pkooo" << std::endl;
}

