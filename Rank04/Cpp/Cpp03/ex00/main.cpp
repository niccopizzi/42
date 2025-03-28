#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap cp("wall-e");
    ClapTrap cp2("evil wall-e");
    std::cout << cp;
    std::cout << cp2;

    cp2.setAttackDamage(2);
    cp2.setEnergyPoints(0);
    cp2.attack("wall-e");
    cp.takeDamage(cp2.getAttackDamage());
    std::cout << "After attack\n";
    std::cout << cp;
    std::cout << cp2;

    cp.beRepaired(20);

    std::cout << cp;
    return (0);
}