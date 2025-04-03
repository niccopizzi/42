#include "Character.hpp"

Character::Character(const std::string& name)
{
    this->name = name;
    inventoryIndex = 0;
   // std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& character)
{
    this->name = character.getName();
    for (int i = 0; i < character.getInventoryIndex(); i++)
    {
        inventory[i] = character.getAMateria(i)->clone();
    }
    inventoryIndex = character.getInventoryIndex();
   // std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& character)
{
    this->name = character.getName();
    for (int i = 0; i < inventoryIndex; i++)
        delete inventory[i];
    for (int i = 0; i < character.getInventoryIndex(); i++)
    {
        inventory[i] = character.getAMateria(i)->clone();
    }
    inventoryIndex = character.getInventoryIndex();
   // std::cout << "Character Copy assignment operator called" << std::endl;
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < inventoryIndex; i++)
        delete inventory[i];
   // std::cout << "Character destructor called" << std::endl;
}

std::string const&  Character::getName() const
{
    return (name);
}
void               Character::equip(AMateria* m)
{
    if (inventoryIndex == 4)
    {
        std::cout <<"Cannot equip " << m->getType() 
                << ", "<< name << "'s inventory is full!" << std::endl;
        return ;
    }
   // std::cout << name << " equips " << m->getType() << std::endl;
    inventory[inventoryIndex] = m;
    inventoryIndex ++;
}

int                 Character::getInventoryIndex() const
{
    return (inventoryIndex);
}

AMateria*           Character::getAMateria(int idx) const
{
    if (idx >= inventoryIndex)
        return (NULL);
    return (inventory[idx]);
}


void                Character::unequip(int idx)
{
    if (idx >= inventoryIndex)
    {
        std::cout << "Unequip error: index is not valid" << std::endl;
        return ;
    }
    for (int i = idx; i < (inventoryIndex - 1); i++)
    {
        inventory[i] = inventory[i + 1];
    }
    std::cout << name << " unequips " << inventory[idx]->getType() << std::endl;
    inventoryIndex = inventoryIndex - 1;
}
void                Character::use(int idx, ICharacter& target)
{
    if (idx >= inventoryIndex)
    {
        std::cout << "Use error: index is not valid" << std::endl;
        return ;
    }
    inventory[idx]->use(target);
}
