#include "Character.hpp"

Character::Character(const std::string& charName) : name(charName)
{
    inventoryIndex = 0;
   // std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& character) : name(character.name)
{
    for (int i = 0; i < character.inventoryIndex; i++)
    {
        inventory[i] = character.inventory[i]->clone();
    }
    inventoryIndex = character.inventoryIndex;
   // std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& character)
{
    this->name = character.name;
    for (int i = 0; i < inventoryIndex; i++)
        delete inventory[i];
    for (int i = 0; i < character.inventoryIndex; i++)
    {
        inventory[i] = character.inventory[i]->clone();
    }
    inventoryIndex = character.inventoryIndex;
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
    if (idx < 0 || idx >= inventoryIndex)
        throw std::out_of_range("Materia index out of range!");
    return (inventory[idx]);
}

void                Character::unequip(int idx)
{
    if (idx < 0 || idx >= inventoryIndex)
    {
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
    if (idx < 0 || idx >= inventoryIndex)
    {
        return ;
    }
    inventory[idx]->use(target);
}
