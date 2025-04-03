#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
   // std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& ice) : AMateria(ice.getType())
{
   // std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& ice)
{
    (void)ice;
   // std::cout << "Ice Copy assignment operator called" << std::endl;
    return (*this);
}

Ice::~Ice()
{
  //  std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    AMateria* clonedIce = new Ice(*this);

    return (clonedIce);
}

void     Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}