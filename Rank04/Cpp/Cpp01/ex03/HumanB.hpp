#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    bool        armed;
    std::string name;
    Weapon*      theWeapon;

public:
    void    attack();
    void    setWeapon(Weapon &theWeapon);
    HumanB(std::string name);
    ~HumanB();
};

# endif // HUMANB_HPP
