#include "HumanA.hpp"

void    HumanA::setWeapon(Weapon& weap)
{   
    theWeapon = &weap;
}

void    HumanA::attack()
{
    std::cout << name << " attacks with " << theWeapon->getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& weap)
{
    this-> name = name;
    this->theWeapon = &weap;
}

HumanA::~HumanA()
{
    //std::cout << "Destroying human " << name << std::endl;
}