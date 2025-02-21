#include "Zombie.hpp"

void    Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie( void )
{
    std::cout << "Zombie being destroyed : " << name << std::endl;
}
