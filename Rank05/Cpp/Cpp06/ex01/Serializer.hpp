#ifndef SERIALIZER_CPP
#define SERIALIZER_CPP

#include "Data.hpp"

class Serializer
{
    private:
        Serializer(); 
        Serializer(const Serializer& ); 
        Serializer& operator=(const Serializer& ); 
        ~Serializer(); 
    public:

        static  uintptr_t   serialize(Data* ptr);
        static  Data*       deserialize(uintptr_t raw);
};

#endif // SERIALIZER.CPP