#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    ClapTrap::hitPoints = 100;
    ClapTrap::energyPoints = 100;
    ClapTrap::attackDamage = 30;
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const FragTrap& st) : ClapTrap(st.getName())
{
    ClapTrap::hitPoints = st.getHitPoints();
    ClapTrap::energyPoints = st.getEnergyPoints();
    ClapTrap::attackDamage = st.getAttackDamage();
    std::cout << "FragTrap copy constructor called\n";
}
FragTrap& FragTrap::operator=(const FragTrap& st)
{
    ClapTrap::name = st.getName();
    ClapTrap::hitPoints = st.getHitPoints();
    ClapTrap::energyPoints = st.getEnergyPoints();
    ClapTrap::attackDamage = st.getAttackDamage();
    std::cout << "FragTrap copy assignment operator called\n";
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap default destructor called\n";
}

std::string  FragTrap::getName() const
{
    return (ClapTrap::name);
}

int FragTrap::getHitPoints() const
{
    return (ClapTrap::hitPoints);
}

int FragTrap::getEnergyPoints() const
{
    return (ClapTrap::energyPoints);
}

int FragTrap::getAttackDamage() const
{
    return (ClapTrap::attackDamage);
}

void    FragTrap::highFivesGuys() const 
{
    std::cout << "FragTrap " << ClapTrap::name << " says: High figh guys!\n";
}

std::ostream&   operator<<(std::ostream& os, const FragTrap& st)
{
     return (os << "Name : " << st.getName()
            << "\nHit Points    : " << st.getHitPoints()
            << "\nEnergy Points : " << st.getEnergyPoints() 
            << "\nAttack Damage : " << st.getAttackDamage() << std::endl);
}