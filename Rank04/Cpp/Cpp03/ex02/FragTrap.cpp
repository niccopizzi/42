#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Default FragTrap constructor called\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    ClapTrap::_hitPoints = 100;
    ClapTrap::_energyPoints = 100;
    ClapTrap::_attackDamage = 30;
    std::cout << "FragTrap constructor called\n";
}

FragTrap::FragTrap(const FragTrap& st) : ClapTrap(st._name)
{
    ClapTrap::_hitPoints = st._hitPoints;
    ClapTrap::_energyPoints = st._energyPoints;
    ClapTrap::_attackDamage = st._attackDamage;
    std::cout << "FragTrap copy constructor called\n";
}
FragTrap& FragTrap::operator=(const FragTrap& st)
{
    ClapTrap::_hitPoints = st._hitPoints;
    ClapTrap::_energyPoints = st._energyPoints;
    ClapTrap::_attackDamage = st._attackDamage;
    std::cout << "FragTrap copy assignment operator called\n";
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called\n";
}

const std::string&  FragTrap::getName() const
{
    return (ClapTrap::_name);
}

int FragTrap::getHitPoints() const
{
    return (ClapTrap::_hitPoints);
}

int FragTrap::getEnergyPoints() const
{
    return (ClapTrap::_energyPoints);
}

int FragTrap::getAttackDamage() const
{
    return (ClapTrap::_attackDamage);
}

void    FragTrap::highFivesGuys() const 
{
    std::cout << "FragTrap " << ClapTrap::_name << " says: High figh guys!\n";
}

std::ostream&   operator<<(std::ostream& os, const FragTrap& st)
{
     return (os << "Name : " << st.getName()
            << "\nHit Points    : " << st.getHitPoints()
            << "\nEnergy Points : " << st.getEnergyPoints() 
            << "\nAttack Damage : " << st.getAttackDamage() << std::endl);
}