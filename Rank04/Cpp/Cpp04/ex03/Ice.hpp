#ifndef ICE_HPP
#define ICE_HPP

#include "Interface.hpp"

class Ice : public AMateria
{
    private:

    public:
        Ice(); /*Constructor*/
        Ice(const Ice& ); /*Copy constructor*/
        Ice& operator=(const Ice& ); /*Copy assignment operator*/
        ~Ice(void); /*Destructor*/

        AMateria* clone() const;
        void      use(ICharacter& target);
};

#endif // ICE.HPP