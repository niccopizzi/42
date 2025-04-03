#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
    inventoryIndex = 0;
    // std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& materiasource)
{
    for (int i = 0; i < materiasource.getInventoryIndex(); i++)
    {
        inventory[i] = materiasource.getAMateria(i);
    }
    inventoryIndex = materiasource.getInventoryIndex();
   //  std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiasource)
{
    for (int i = 0 ; i < inventoryIndex; i++)
        delete inventory[i];
    for (int i = 0; i < materiasource.getInventoryIndex(); i++)
    {
        inventory[i] = materiasource.getAMateria(i);
    }
    inventoryIndex = materiasource.getInventoryIndex();
    // std::cout << "MateriaSource Copy assignment operator called" << std::endl;
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0 ; i < inventoryIndex; i++)
        delete inventory[i];
    // std::cout << "MateriaSource destructor called" << std::endl;
}


void    MateriaSource::learnMateria(AMateria* m)
{
    if (inventoryIndex == 4)
        std::cout << "Can't learn new Materia, inventory is full" << std::endl;
    inventory[inventoryIndex] = m;
    inventoryIndex ++;
}

AMateria*    MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < inventoryIndex; i++)
    {
        if (inventory[i]->getType() == type)
            return (inventory[i]->clone());
    }
    return (0);
}


int         MateriaSource::getInventoryIndex() const
{
    return (inventoryIndex);
}

AMateria*   MateriaSource::getAMateria(int idx) const
{
    if (idx >= inventoryIndex)
        return (NULL);
    return (inventory[idx]);
}