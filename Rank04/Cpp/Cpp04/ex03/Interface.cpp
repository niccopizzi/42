#include "Interface.hpp"

AMateria::AMateria(std::string const& type)
{
    this->type = type;
   // std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& amateria)
{
    this->type = amateria.getType();
  //  std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& amateria)
{
    this->type = amateria.getType();
   // std::cout << "AMateria Copy assignment operator called" << std::endl;
    return (*this);
}

AMateria::~AMateria()
{
   // std::cout << "AMateria destructor called" << std::endl;
}

std::string const&  AMateria::getType() const
{
    return (this->type);
}

void    AMateria::use(ICharacter& target)
{
    std::cout << "* uses materia on " << target.getName() << std::endl;
}