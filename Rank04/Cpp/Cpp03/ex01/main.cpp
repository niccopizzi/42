#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap evilwalle("evilwall-e");
    ClapTrap  walle("wall-e");
    std::cout << evilwalle;
    //evilwalle.guardGate();
    evilwalle.attack("wall-e");
    walle.takeDamage(20);
    std::cout << walle;
    std::cout <<evilwalle;

    std::cout << ScavTrap(evilwalle);

    ScavTrap newVall("test");

    newVall = evilwalle;
    std::cout << newVall;
    return (0);
}