#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
    inventoryIndex = 0;
    // std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& materiasource)
{
    for (int i = 0; i < materiasource.inventoryIndex; i++)
    {
        inventory[i] = materiasource.inventory[i];
    }
    inventoryIndex = materiasource.inventoryIndex;
   //  std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiasource)
{
    for (int i = 0 ; i < inventoryIndex; i++)
        delete inventory[i];
    for (int i = 0; i < materiasource.inventoryIndex; i++)
    {
        inventory[i] = materiasource.inventory[i];
    }
    inventoryIndex = materiasource.inventoryIndex;
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
    {
        std::cout << "Can't learn new Materia, inventory is full" << std::endl;
        return;
    }
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
        throw std::out_of_range("Materia index out of range!");
    return (inventory[idx]);
}