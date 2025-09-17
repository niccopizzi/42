#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template<typename T>
class Array
{
    private:
        T*              theArray;
        unsigned int    _size;
    public:
        Array() :   _size(0)
        {
            std::cout << "Default constructor called\n";
        }

        Array(unsigned int n) : theArray(new T[n]()),
                                _size(n)
        {
            std::cout << "Size constructor called\n";
        }

        Array(const Array& ar) :    theArray(new T[ar._size]()),
                                    _size(ar._size)
        {
            for (unsigned int i = 0; i < _size; i++)
                theArray[i] = ar[i];
        }

        Array& operator=(const Array& ar)
        {
            delete[] theArray;
            theArray =  new T[ar._size]();
            for (unsigned int i = 0; i < ar._size; i++)
                theArray[i] = ar[i];
            return (*this);
        }

        ~Array(void)
        {
            delete[] theArray;
            std::cout << "Array destructor called, memory freed\n";
        }

        T&  operator[] (unsigned int index)
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return (theArray[index]);
        }

        const T&  operator[] (unsigned int index) const
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return (theArray[index]);
        }

        unsigned int     size() const
        {
            return (_size);
        }
};

#endif // ARRAY.HPP