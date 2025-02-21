#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* theHorde = new Zombie[N];
    Zombie* tmp = theHorde;

    for (int i = 0; i < N; i++)
    {
        if (i % 2)
            (tmp + i)->setName("even");
        else
           (tmp + i)->setName(name);
    }
    return (theHorde);
}