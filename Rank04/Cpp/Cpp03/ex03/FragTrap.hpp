#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:

public:
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& ft);
    FragTrap& operator=(const FragTrap& ft);
    ~FragTrap();


    std::string  getName() const;
    int          getHitPoints() const;
    int          getEnergyPoints() const;
    int          getAttackDamage() const;

    virtual void attack(const std::string& target);
    void highFivesGuys(void) const;
};

std::ostream&   operator<<(std::ostream& os, const FragTrap& ft);

#endif // FRAGTRAP_HPP