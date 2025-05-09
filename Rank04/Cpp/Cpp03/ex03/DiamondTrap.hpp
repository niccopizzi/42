#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    const std::string _name;
    
public:
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& dt);
    DiamondTrap& operator=(const DiamondTrap& dt);
    ~DiamondTrap();
    
    const std::string&  getName() const;
    int             getHitPoints() const;
    int             getEnergyPoints() const;
    int             getAttackDamage() const;

    void            whoAmI() const;
    void            attack(const std::string& target);
};

std::ostream&   operator<<(std::ostream& os, const DiamondTrap& dt);

#endif  // DIAMONDTRAP_HPP