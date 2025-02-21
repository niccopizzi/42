#include "Zombie.hpp"

int main(void)
{
    int     i;
    int     n;
    Zombie  *newHorde;

    n = 20;
    newHorde = zombieHorde(n, "odd");
    i = 0;
    while (i < n)
    {
        (newHorde + i)->announce();
        
        i++;
    }
    if (newHorde)
        delete[] newHorde;
    return (0);
}