#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    private:

    public:
        Cat(/*args*/); /*Default constructor*/
        Cat(const Cat& ); /*Default copy constructor*/
        Cat& operator=(const Cat& ); /*Default copy assignment operator*/
        ~Cat(void); /*Default destructor*/

        void    makeSound() const;
};

#endif // CAT.HPP