#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    ClapTrap::hitPoints = 100;
    ClapTrap::energyPoints = 50;
    ClapTrap::attackDamage = 20;
    inGuard = false;
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& st) : ClapTrap(st.getName())
{
    ClapTrap::hitPoints = st.getHitPoints();
    ClapTrap::energyPoints = st.getEnergyPoints();
    ClapTrap::attackDamage = st.getAttackDamage();
    inGuard = st.getGuard();
    std::cout << "ScavTrap copy constructor called\n";
}
ScavTrap& ScavTrap::operator=(const ScavTrap& st)
{
    ClapTrap::name = st.getName();
    ClapTrap::hitPoints = st.getHitPoints();
    ClapTrap::energyPoints = st.getEnergyPoints();
    ClapTrap::attackDamage = st.getAttackDamage();
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
    return (ClapTrap::name);
}

int ScavTrap::getHitPoints() const
{
    return (ClapTrap::hitPoints);
}

int ScavTrap::getEnergyPoints() const
{
    return (ClapTrap::energyPoints);
}

int ScavTrap::getAttackDamage() const
{
    return (ClapTrap::attackDamage);
}

bool ScavTrap::getGuard() const
{
    return (inGuard);
}

void ScavTrap::guardGate()
{
    inGuard = true;
    std::cout << "ScavTrap " << ClapTrap::name << " is now in guard\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (!ClapTrap::energyPoints)
    {
        std::cout << "ScavTrap " << ClapTrap::name << " wants to attack " << target
                    << "but has no energy points\n";
        return;
    }
    if (ClapTrap::hitPoints <= 0)
    {
        std::cout << "ScavTrap " << ClapTrap::name << " wants to attack " << target
                    << "but has no hit points\n";
        return;
    }
    std::cout << "ScavTrap " << ClapTrap::name << " attacks " << target
            << " causing " << ClapTrap::attackDamage << " points of damage!\n";
    ClapTrap::energyPoints = ClapTrap::energyPoints - 1;
}

std::ostream&   operator<<(std::ostream& os, const ScavTrap& st)
{
     return (os << "Name : " << st.getName()
            << "\nHit Points    : " << st.getHitPoints()
            << "\nEnergy Points : " << st.getEnergyPoints() 
            << "\nAttack Damage : " << st.getAttackDamage() << std::endl);
}