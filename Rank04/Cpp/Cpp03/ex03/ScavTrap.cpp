#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    ScavTrap::hitPoints = 100;
    ScavTrap::energyPoints = 50;
    ScavTrap::attackDamage = 20;
    inGuard = false;
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& st) : ClapTrap(st.getName())
{
    ScavTrap::hitPoints = st.getHitPoints();
    ScavTrap::energyPoints = st.getEnergyPoints();
    ScavTrap::attackDamage = st.getAttackDamage();
    inGuard = st.getGuard();
    std::cout << "ScavTrap copy constructor called\n";
}
ScavTrap& ScavTrap::operator=(const ScavTrap& st)
{
    ScavTrap::name = st.getName();
    ScavTrap::hitPoints = st.getHitPoints();
    ScavTrap::energyPoints = st.getEnergyPoints();
    ScavTrap::attackDamage = st.getAttackDamage();
    inGuard = st.getGuard();
    std::cout << "ScavTrap copy assignment operator called\n";
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap default destructor called\n";
}

std::string  ScavTrap::getName() const
{
    return (name);
}

int ScavTrap::getHitPoints() const
{
    return (hitPoints);
}

int ScavTrap::getEnergyPoints() const
{
    return (energyPoints);
}

int ScavTrap::getAttackDamage() const
{
    return (attackDamage);
}

bool ScavTrap::getGuard() const
{
    return (inGuard);
}

void ScavTrap::guardGate()
{
    inGuard = true;
    std::cout << "ScavTrap " << name << " is now in guard\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (!ClapTrap::energyPoints)
    {
        std::cout << "ScavTrap " << name << " wants to attack " << target
                    << "but has no energy points\n";
        return;
    }
    if (ClapTrap::hitPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " wants to attack " << target
                    << "but has no hit points\n";
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target
            << " causing " << attackDamage << " points of damage!\n";
    energyPoints = energyPoints - 1;
}

std::ostream&   operator<<(std::ostream& os, const ScavTrap& st)
{
     return (os << "Name : " << st.getName()
            << "\nHit Points    : " << st.getHitPoints()
            << "\nEnergy Points : " << st.getEnergyPoints() 
            << "\nAttack Damage : " << st.getAttackDamage() << std::endl);
}