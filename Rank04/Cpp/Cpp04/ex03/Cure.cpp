#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
  //  std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& cure) : AMateria(cure.getType())
{
   // std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& cure)
{
    this->type = cure.getType();
   // std::cout << "Cure Copy assignment operator called" << std::endl;
    return (*this);
}

Cure::~Cure()
{
   // std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
    AMateria* clonedCure = new Cure();

    return (clonedCure);
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}