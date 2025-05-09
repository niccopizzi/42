#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    private:

    public:
        WrongCat(); /*Default constructor*/
        WrongCat(const WrongCat& ); /*Default copy constructor*/
        WrongCat& operator=(const WrongCat& ); /*Default copy assignment operator*/
        ~WrongCat(void); /*Default destructor*/

        void    makeSound() const;
};
#endif // WRONGCAT.HPP