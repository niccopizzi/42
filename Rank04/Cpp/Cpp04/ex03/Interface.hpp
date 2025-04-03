#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(std::string const& type); /*Constructor*/
        AMateria(const AMateria& ); /*Copy constructor*/
        AMateria& operator=(const AMateria& ); /*Copy assignment operator*/
        virtual ~AMateria(void) = 0; /*Destructor*/

        std::string const&  getType() const; 

        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target);
};

class ICharacter
{
    public:
        virtual ~ICharacter() {};
        virtual std::string const & getName() const = 0;
        virtual void                equip(AMateria*m) = 0;
        virtual void                unequip(int idx) = 0;
        virtual void                use(int idx, ICharacter& target) = 0;
};

#endif // AMATERIA.HPP