#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
{
    this->name = name;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& cp)
{
    name = cp.getName();
    hitPoints = cp.getHitPoints();
    energyPoints = cp.getEnergyPoints();
    attackDamage = cp.getAttackDamage();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& cp)
{
    name = cp.getName();
    hitPoints = cp.getHitPoints();
    energyPoints = cp.getEnergyPoints();
    attackDamage = cp.getAttackDamage();

    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Default destructor called\n";
}

std::string ClapTrap::getName() const
{
    return (name);
}
int ClapTrap::getHitPoints() const
{
    return (hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
    return (energyPoints);
}
int ClapTrap::getAttackDamage() const
{
    return (attackDamage);
}

void ClapTrap::setName(const std::string& newName)
{
    name = newName;
}
void ClapTrap::setHitPoints(const int newHitPoints)
{
    hitPoints = newHitPoints;
}
void ClapTrap::setEnergyPoints(const int newEnergyPoints)
{
    energyPoints = newEnergyPoints;
}
void ClapTrap::setAttackDamage(const int newAttackDamage)
{
    attackDamage = newAttackDamage;
}

void ClapTrap::attack(const std::string& target)
{
    if (!energyPoints)
    {
        std::cout << "ClapTrap " << name << " wants to attack " << target
                    << "but has no energy points\n";
        return;
    }
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " wants to attack " << target
                    << "but has no hit points\n";
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target
            << " causing " << attackDamage << " points of damage!\n";
    energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " got attacked and lost " << amount 
                << " of hit points\n";
    hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!energyPoints)
    {
        std::cout << "ClapTrap " << name << " wants to repair itself "
                    << "but has no energy points\n";
        return;
    }
    std::cout << "ClaTrap " << name << "repaired itself and gained " << amount 
                << " of hit points\n";
    hitPoints += amount;
    energyPoints --;

}

std::ostream& operator<<(std::ostream& os, const ClapTrap& cp)
{
    return (os << "Name : " << cp.getName() 
            << "\nHit Points    : " << cp.getHitPoints()
            << "\nEnergy Points : " << cp.getEnergyPoints() 
            << "\nAttack Damage : " << cp.getAttackDamage()<< std::endl);
}