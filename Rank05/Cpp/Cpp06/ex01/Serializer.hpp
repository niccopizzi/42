#ifndef SERIALIZER_CPP
#define SERIALIZER_CPP

#include "Data.hpp"

class Serializer
{
    private:
        Serializer(); 
    public:
        Serializer(const Serializer& ); 
        Serializer& operator=(const Serializer& ); 
        ~Serializer(); 

        static  uintptr_t   serialize(Data* ptr);
        static  Data*       deserialize(uintptr_t raw);
};

#endif // SERIALIZER.CPP