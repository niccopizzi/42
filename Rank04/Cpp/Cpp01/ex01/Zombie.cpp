#include "Zombie.hpp"

void    Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void    Zombie::setName(std::string Zombiename)
{
    name = Zombiename;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::Zombie()
{

    this->name = "";
}
Zombie::~Zombie( void )
{
    std::cout << "Zombie being destroyed : " << name << std::endl;
}