#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void    iter(T* array, size_t len, void (*func)(T& elem))
{
    if (array == NULL || func == NULL)
        return;
    for (size_t i = 0; i < len; i++)
    {
        func(*(array + i)); 
    }
}

template<typename T>
void    iter(const T* array, size_t len, void (*func)(const T& elem))
{
    if (array == NULL || func == NULL)
        return;
    for (size_t i = 0; i < len; i++)
    {
        func(*(array + i)); 
    }
}

#endif // ITER.HPP