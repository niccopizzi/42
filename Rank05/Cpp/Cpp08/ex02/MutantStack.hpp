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

            iterator& operator++()
            {
                ++_ptr;
                return (*this);
            }    
            iterator& operator--()
            {
                --_ptr;
                return (*this);
            }

            T&       operator*()
            {
                return (*_ptr);
            }

            bool operator!=(const iterator& other) 
            {
                return (_ptr != other._ptr);
            }
        };

        struct reverse_iterator
        {
            T*  _ptr;

            reverse_iterator(T* ptr) : _ptr(ptr)
            {
                //std::cout << "Reverse iterator constructor called\n";
            }

            reverse_iterator& operator++()
            {
                --_ptr;
                return (*this);
            }    
            reverse_iterator& operator--()
            {
                ++_ptr;
                return (*this);
            }

            T&       operator*()
            {
                return (*_ptr);
            }

            bool operator!=(const reverse_iterator& other) 
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

        reverse_iterator rbegin()
        {
            return (reverse_iterator(end()._ptr - 1));
        }
        reverse_iterator rend()
        {
            return (reverse_iterator(begin()._ptr - 1));
        }
};


#endif // MUTANTSTACK.HPP