#ifndef     HUMANA_HPP
# define    HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon*  theWeapon;

    public:
        void    attack();
        void    setWeapon(Weapon& theWeapon);
        HumanA(std::string name, Weapon& weap);
        ~HumanA();
};


#endif