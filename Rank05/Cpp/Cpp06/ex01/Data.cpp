#include "Data.hpp"

Data::Data()
{
    for (size_t i = 0; i < 8; i++)
        ptrs[i] = 0;
    size = 0;
    first = 0;
    std::cout << "Data constructor called" << std::endl;
}

Data::Data(const Data& data)
{
    for (size_t i = 0; i < 8; i++)
        ptrs[i] = data.ptrs[i];
    std::cout << "Data copy constructor called" << std::endl;
}

Data& Data::operator=(const Data& data)
{
    for (size_t i = 0; i < 8; i++)
    {
        ptrs[i] = data.ptrs[i];
    }
    std::cout << "Data Copy assignment operator called" << std::endl;
    return (*this);
}

int   Data::getFirst() const
{
    return (ptrs[first]);
}

int   Data::getLast() const
{
    return (ptrs[(first + size) % 8]);
}

int  Data::getElemByIndex(size_t i) const
{
    if (i >= 8)    
        return (0);
    return (ptrs[i]);
}

void   Data::enqueue(int ptr)
{
    if (size == 8)
    {
        std::cout << "Ring buffer is full, no queue allowed\n";
        return;
    }
    ptrs[(first + size) % 8] = ptr;
    size++;
}

void    Data::dequeue()
{
    if (size == 0)
    {
        std::cout << "Ring buffer is empty, no dequeue possible\n";
        return;
    }
    ptrs[(first)] = 0;
    size--;
    first = (first + 1) % 8;
}

Data::~Data()
{
    for (size_t i = 0; i < 8; i++)
        ptrs[i] = 0;
    std::cout << "Data destructor called" << std::endl;
}

std::ostream&   operator<<(std::ostream& os, const Data& r)
{
    for (size_t i = 0; i < 8; i++)
    {
        os << "Element at index " << i << " -> " << r.getElemByIndex(i) << "\n";
    }
    return (os);
}