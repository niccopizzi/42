#include "Zombie.hpp"

void    randomChump (std::string name)
{
    Zombie  theZombie  = Zombie(name);
    theZombie.announce();
}