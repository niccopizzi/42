#include "Cat.hpp"
#include "Dog.hpp"
#include <string>

int main(void)
{

    Animal* array[100];

    for (int i = 0; i < 100; i++)
    {
        if (i < 50)
            array[i] = new Dog();
        else
            array[i] = new Cat();
    }

    for (int i = 0; i < 100; i++)
    {
        delete array[i];
    }

    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        i->makeSound();
        j->makeSound();
    
        delete j; 
        delete i;
    }
    return (0);
}