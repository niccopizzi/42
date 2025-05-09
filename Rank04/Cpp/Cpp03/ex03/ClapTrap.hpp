#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& cp);
    ClapTrap& operator=(const ClapTrap& cp);
    ~ClapTrap();

    virtual const std::string& getName() const;
    virtual int          getHitPoints() const;
    virtual int          getEnergyPoints() const;
    virtual int          getAttackDamage() const;

    virtual void setHitPoints(const int newHitPoints);
    virtual void setEnergyPoints(const int newEnergyPoints);
    virtual void setAttackDamage(const int newAttackDamage);
 
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

std::ostream& operator<<(std::ostream& os, const ClapTrap& cp);

#endif  // CLAPTRAP_HPP