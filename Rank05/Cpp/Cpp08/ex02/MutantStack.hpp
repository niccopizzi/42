#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>


template <typename T>
class MutantStack : public std::stack<T>
{
    private:

    public :
        struct iterator
        {
            T*  _ptr;
            iterator(T* ptr) : _ptr(ptr)
            {
                //std::cout << "iterator constructor called\n";
            }

            iterator operator++()
            {
                ++_ptr;
                return (*this);
            }    
            iterator operator--()
            {
                --_ptr;
                return (*this);
            }

            T       operator*()
            {
                return (*_ptr);
            }

            bool operator!=(iterator& other) 
            {
                return (_ptr != other._ptr);
            }
        };

        iterator    begin()
        {
            return (iterator(&std::stack<T>::c[0]));
        }
        
        iterator    end()
        {
            return (iterator(&std::stack<T>::c[std::stack<T>::size()]));
        }

};


#endif // MUTANTSTACK.HPP