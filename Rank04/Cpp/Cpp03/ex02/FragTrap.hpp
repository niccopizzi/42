#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:

public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& ft);
    FragTrap& operator=(const FragTrap& ft);
    ~FragTrap();


    const std::string&  getName() const;
    int          getHitPoints() const;
    int          getEnergyPoints() const;
    int          getAttackDamage() const;
    bool         getGuard() const;

    void highFivesGuys(void) const;
};

std::ostream&   operator<<(std::ostream& os, const FragTrap& ft);

#endif // FRAGTRAP_HPP