#include "Weapon.hpp"

const   std::string& Weapon::getType()
{
    return (type);
}

void    Weapon::setType(std::string newType)
{
   type = newType;
}

Weapon::Weapon(std::string weaponType)
{
    type = weaponType;
}

Weapon::Weapon( void )
{
    type = "null";
} 

Weapon::~Weapon( void )
{
    //std::cout << "removing the weapon with name : " << type << "\n";
}