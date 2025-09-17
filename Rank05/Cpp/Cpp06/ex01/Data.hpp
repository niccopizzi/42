#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <stdint.h>

class Data
{
    private:
        int     ptrs[8];
        size_t  size;
        size_t  first;
        
    public:
        Data();
        Data(const Data& );
        Data& operator=(const Data& );
        ~Data(); 

        int     getFirst() const;
        int     getLast() const;
        int     getElemByIndex(size_t i) const;
        void    enqueue(int ptr);
        void    dequeue();
};

std::ostream&   operator<<(std::ostream& os, const Data& r);

#endif // DATA.HPP