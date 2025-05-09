#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name) : _name(name)
{
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& cp) : _name(cp._name)
{
    _hitPoints = cp._hitPoints;
    _energyPoints = cp._energyPoints;
    _attackDamage = cp._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& cp)
{
    _hitPoints = cp._hitPoints;
    _energyPoints = cp._energyPoints;
    _attackDamage = cp._attackDamage;

    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called\n";
}

const std::string& ClapTrap::getName() const
{
    return (_name);
}
int ClapTrap::getHitPoints() const
{
    return (_hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
    return (_energyPoints);
}
int ClapTrap::getAttackDamage() const
{
    return (_attackDamage);
}

void ClapTrap::setHitPoints(const int newHitPoints)
{
    _hitPoints = newHitPoints;
}

void ClapTrap::setEnergyPoints(const int newEnergyPoints)
{
    _energyPoints = newEnergyPoints;
}

void ClapTrap::setAttackDamage(const int newAttackDamage)
{
    _attackDamage = newAttackDamage;
}

void ClapTrap::attack(const std::string& target)
{
    if (!_energyPoints)
    {
        std::cout << "ClapTrap " << _name << " wants to attack " << target
                    << "but has no energy points\n";
        return;
    }
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " wants to attack " << target
                    << "but has no hit points\n";
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target
            << " causing " << _attackDamage << " points of damage!\n";
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << _name << " got attacked and lost " << amount 
                << " of hit points\n";
    _hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!_energyPoints)
    {
        std::cout << "ClapTrap " << _name << " wants to repair itself "
                    << "but has no energy points\n";
        return;
    }
    std::cout << "ClaTrap " << _name << "repaired itself and gained " << amount 
                << " hit points\n";
    _hitPoints += amount;
    _energyPoints --;

}

std::ostream& operator<<(std::ostream& os, const ClapTrap& cp)
{
    return (os << "Name : " << cp.getName() 
            << "\nHit Points    : " << cp.getHitPoints()
            << "\nEnergy Points : " << cp.getEnergyPoints() 
            << "\nAttack Damage : " << cp.getAttackDamage()<< std::endl);
}