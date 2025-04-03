#ifndef CURE_HPP
#define CURE_HPP

#include "Interface.hpp"

class Cure : public AMateria
{
    private:

    public:
        Cure(); /*Constructor*/
        Cure(const Cure& ); /*Copy constructor*/
        Cure& operator=(const Cure& ); /*Copy assignment operator*/
        ~Cure(void); /*Destructor*/

        AMateria* clone() const;
        void       use(ICharacter& target);
};

#endif // CURE.HPP