#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "Default DiamondTrap constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name), 
                                                    ScavTrap(), FragTrap() , _name(name)
{
    ClapTrap::_name = name + "_clap_name";
    _energyPoints = 50;
    std::cout << "DiamondTrap constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& dt) :  ClapTrap(dt._name), ScavTrap(dt._name), FragTrap(dt._name)
{
    std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& dt)
{
    _attackDamage = dt._attackDamage;
    _energyPoints = dt._energyPoints;
    _hitPoints = dt._energyPoints;
    std::cout << "DiamondTrap copy assignment operator called\n";
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called\n";
}

const std::string& DiamondTrap::getName() const
{
    return (_name);
}

int DiamondTrap::getHitPoints() const 
{
    return (_hitPoints);
}

int DiamondTrap::getEnergyPoints() const 
{
    return (_energyPoints);
}

int DiamondTrap::getAttackDamage() const
{
    return (_attackDamage);
}

void DiamondTrap::whoAmI() const
{
    std::cout << "Diamond Trap name " << _name 
            <<"\nClapTrap name " << ClapTrap::_name << std::endl;
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