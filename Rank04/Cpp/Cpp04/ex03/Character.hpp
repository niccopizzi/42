#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Interface.hpp"

class Character : public ICharacter
{
    private:
        std::string             name;
        AMateria*               inventory[4];
        int                     inventoryIndex;
    public:
        Character(const std::string& charName); /*Constructor*/
        Character(const Character& ); /*Copy constructor*/
        Character& operator=(const Character& ); /*Copy assignment operator*/
        ~Character(); /*Destructor*/

        std::string const&  getName() const;
        int                 getInventoryIndex() const;
        AMateria*           getAMateria(int idx) const;
        void                equip(AMateria* m);
        void                unequip(int idx);
        void                use(int idx, ICharacter& target);
};

#endif // CHARACTER.HPP