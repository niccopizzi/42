#ifndef WRONG_HPP
#define WRONG_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal(); /*Default constructor*/
        WrongAnimal(const WrongAnimal& ); /*Default copy constructor*/
        WrongAnimal& operator=(const WrongAnimal& ); /*Default copy assignment operator*/
        virtual ~WrongAnimal(void); /*Default destructor*/

        virtual void makeSound() const;

        std::string  getType() const;
};


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
#endif // WRONG.HPP