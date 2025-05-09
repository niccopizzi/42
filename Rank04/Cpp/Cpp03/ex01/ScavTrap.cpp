#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    ClapTrap::_hitPoints = 100;
    ClapTrap::_energyPoints = 50;
    ClapTrap::_attackDamage = 20;
    inGuard = false;
    std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& st) : ClapTrap(st._name)
{
    ClapTrap::_hitPoints = st._hitPoints;
    ClapTrap::_energyPoints = st._hitPoints;
    ClapTrap::_attackDamage = st._hitPoints;
    inGuard = st.inGuard;
    std::cout << "ScavTrap copy constructor called\n";
}
ScavTrap& ScavTrap::operator=(const ScavTrap& st)
{
    ClapTrap::_hitPoints = st.getHitPoints();
    ClapTrap::_energyPoints = st.getEnergyPoints();
    ClapTrap::_attackDamage = st.getAttackDamage();
    inGuard = st.getGuard();
    std::cout << "ScavTrap copy assignment operator called\n";
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called\n";
}

const std::string&  ScavTrap::getName() const
{
    return (ClapTrap::_name);
}

int ScavTrap::getHitPoints() const
{
    return (ClapTrap::_hitPoints);
}

int ScavTrap::getEnergyPoints() const
{
    return (ClapTrap::_energyPoints);
}

int ScavTrap::getAttackDamage() const
{
    return (ClapTrap::_attackDamage);
}

bool ScavTrap::getGuard() const
{
    return (inGuard);
}

void ScavTrap::guardGate()
{
    inGuard = true;
    std::cout << "ScavTrap " << ClapTrap::_name << " is now in guard\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (!ClapTrap::_energyPoints)
    {
        std::cout << "ScavTrap " << ClapTrap::_name << " wants to attack " << target
                    << "but has no energy points\n";
        return;
    }
    if (ClapTrap::_hitPoints <= 0)
    {
        std::cout << "ScavTrap " << ClapTrap::_name << " wants to attack " << target
                    << "but has no hit points\n";
        return;
    }
    if (inGuard)
    {
        std::cout << "ScavTrap " << ClapTrap::_name << " is in guard and cannot attack!\n";
        return ;
    }
    std::cout << "ScavTrap " << ClapTrap::_name << " attacks " << target
            << " causing " << ClapTrap::_attackDamage << " points of damage!\n";
    ClapTrap::_energyPoints -= 1;
}

std::ostream&   operator<<(std::ostream& os, const ScavTrap& st)
{
     return (os << "Name : " << st.getName()
            << "\nHit Points    : " << st.getHitPoints()
            << "\nEnergy Points : " << st.getEnergyPoints() 
            << "\nAttack Damage : " << st.getAttackDamage() << std::endl);
}