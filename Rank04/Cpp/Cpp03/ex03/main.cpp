#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap dt("test");

    std::cout << dt;
    dt.whoAmI();
    dt.DiamondTrap::attack("azzuazz");
   /*  std::cout << FragTrap("frag");
    std::cout << ScavTrap("scav"); */

    return (0);
}