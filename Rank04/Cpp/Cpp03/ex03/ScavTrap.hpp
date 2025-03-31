#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
    bool    inGuard;
public:
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& st);
    ScavTrap& operator=(const ScavTrap& st);
    ~ScavTrap();

    std::string  getName() const;
    int          getHitPoints() const;
    int          getEnergyPoints() const;
    int          getAttackDamage() const;
    bool         getGuard() const;

    virtual void attack(const std::string& target);
    void            guardGate();
};

std::ostream&   operator<<(std::ostream& os, const ScavTrap& st);

#endif //SCAVTRAP_HPP
