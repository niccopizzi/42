#include "Zombie.hpp"

int main(void)
{
    Zombie* thezomb =  newZombie("Jackson");
    
    thezomb->announce();
    randomChump("Five");
    delete (thezomb);
    return (0);
}