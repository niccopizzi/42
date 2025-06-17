#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

template<typename T>
void easyfind(T& container, int n)
{
    typename T::iterator   it = container.begin();
    typename T::iterator   end = container.end();

    for (; it != end; it++)
    {
        if (*it == n)
        {
            std::cout << "Found " << n << '\n';
            return;
        }
    }
    throw   std::out_of_range("Did not find any occurence");
}

#endif // EASYFIND.HPP