#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    FragTrap::hitPoints = 100;
    FragTrap::energyPoints = 100;
    FragTrap::attackDamage = 30;
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const FragTrap& st) : ClapTrap(st.getName())
{
    FragTrap::hitPoints = st.getHitPoints();
    FragTrap::energyPoints = st.getEnergyPoints();
    FragTrap::attackDamage = st.getAttackDamage();
    std::cout << "FragTrap copy constructor called\n";
}
FragTrap& FragTrap::operator=(const FragTrap& st)
{
    FragTrap::name = st.getName();
    FragTrap::hitPoints = st.getHitPoints();
    FragTrap::energyPoints = st.getEnergyPoints();
    FragTrap::attackDamage = st.getAttackDamage();
    std::cout << "FragTrap copy assignment operator called\n";
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap default destructor called\n";
}

std::string  FragTrap::getName() const
{
    return (name);
}

int FragTrap::getHitPoints() const
{
    return (hitPoints);
}

int FragTrap::getEnergyPoints() const
{
    return (energyPoints);
}

int FragTrap::getAttackDamage() const
{
    return (attackDamage);
}

void FragTrap::attack(const std::string& target)
{
    if (!ClapTrap::energyPoints)
    {
        std::cout << "FragTrap " << ClapTrap::name << " wants to attack " << target
                    << "but has no energy points\n";
        return;
    }
    if (ClapTrap::hitPoints <= 0)
    {
        std::cout << "FragTrap " << ClapTrap::name << " wants to attack " << target
                    << "but has no hit points\n";
        return;
    }
    std::cout << "FragTrap " << ClapTrap::name << " attacks " << target
            << " causing " << ClapTrap::attackDamage << " points of damage!\n";
    ClapTrap::energyPoints = ClapTrap::energyPoints - 1;
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