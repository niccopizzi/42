#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void    iter(T* array, size_t len, void (*func)(T& elem))
{
    for (size_t i = 0; i < len; i++)
    {
        func(*(array + i)); 
    }
}

#endif // ITER.HPP