#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "Interface.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void        learnMateria(AMateria*) = 0;
        virtual AMateria*   createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
    private:
        AMateria*   inventory[4];
        int         inventoryIndex;
    public:
        MateriaSource(); /*Constructor*/
        MateriaSource(const MateriaSource& ); /*Copy constructor*/
        MateriaSource& operator=(const MateriaSource& ); /*Copy assignment operator*/
        ~MateriaSource(); /*Destructor*/

        void            learnMateria(AMateria*);
        AMateria*       createMateria(std::string const & type);

        int             getInventoryIndex() const;
        AMateria*       getAMateria(int idx) const;
};

#endif // MATERIASOURCE.HPP