#include "Cat.hpp"
#include "Dog.hpp"
#include <string>

int main(void)
{
        //Test 1
     /* Animal* array[100];

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
    }  */

        //Test 2
    /* {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        delete j;
        delete i;

        return (0);
    } */
    {
        
        Dog* dg = new Dog(); 
        Brain& b = dg->getBrain();

        b.setIdeas(0, "I am a dog!");
        std::cout << "The dog 1 thinks : " << b.getIdeas(0) << std::endl;

        Dog* dg2 = new Dog(*dg);
        Brain& b2 = dg2->getBrain();

        std::cout << " The dog 2 thinks : " << b2.getIdeas(0) << std::endl;
        b.setIdeas(0, "The only thing that I know is that I don't know");
        std::cout << "After becoming conscious of himself the dog 1 now thinks : " 
            << b.getIdeas(0) << "\nThe dog 2 instead thinks : " << b2.getIdeas(0) << std::endl;
        delete dg;
        delete dg2;
    }
    return (0);
}