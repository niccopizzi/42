#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    const std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& cp);
    ClapTrap& operator=(const ClapTrap& cp);
    ~ClapTrap();


    const std::string& getName() const;
    int          getHitPoints() const;
    int          getEnergyPoints() const;
    int          getAttackDamage() const;

    void setName(const std::string& newName);
    void setHitPoints(const int newHitPoints);
    void setEnergyPoints(const int newEnergyPoints);
    void setAttackDamage(const int newAttackDamage);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

std::ostream& operator<<(std::ostream& os, const ClapTrap& cp);

#endif  // CLAPTRAP_HPP