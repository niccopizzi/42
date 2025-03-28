#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string name;
public:
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& dt);
    DiamondTrap& operator=(const DiamondTrap& dt);
    ~DiamondTrap();
    
    std::string     getName() const;
    std::string     getClapTrapName() const;
    int             getHitPoints() const;
    int             getEnergyPoints() const;
    int             getAttackDamage() const;
};

std::ostream&   operator<<(std::ostream& os, const DiamondTrap& dt);

#endif  // DIAMONDTRAP_HPP