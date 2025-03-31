#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    this->name = name;
    energyPoints = 50;
    ClapTrap::name = name + "_clap_name";
    std::cout << "DiamondTrap default constructor called\n";
}
DiamondTrap::DiamondTrap(const DiamondTrap& dt) :  ClapTrap(dt.getName()), ScavTrap(dt.getName()), FragTrap(dt.getName())
{
    std::cout << "DiamondTrap copy constructor called\n";
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& dt)
{
    (void)dt;
    std::cout << "DiamondTrap copy assignment operator called\n";
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called\n";
}

std::string     DiamondTrap::getName() const
{
    return (name);
}

int DiamondTrap::getHitPoints() const 
{
    return (hitPoints);
}

int DiamondTrap::getEnergyPoints() const 
{
    return (energyPoints);
}

int DiamondTrap::getAttackDamage() const
{
    return (attackDamage);
}

void DiamondTrap::whoAmI() const
{
    std::cout << "Diamond Trap name " << name 
            <<"\nClapTrap name " << ClapTrap::name << std::endl;
}


void DiamondTrap::attack(const std::string& target)
{
    this->ScavTrap::attack(target);
}

std::ostream&   operator<<(std::ostream& os, const DiamondTrap& dt)
{
    return (os << "     Name     : " << dt.getName()
            << "\nHit Points    : " << dt.getHitPoints()
            << "\nEnergy Points : " << dt.getEnergyPoints() 
            << "\nAttack Damage : " << dt.getAttackDamage() << std::endl);
}