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
    typename T::iterator f = std::find(container.begin(), container.end(), n);

    if (f == container.end())
        throw std::runtime_error("Did not find any occurence");
    else
        std::cout << "Number " << n << " is present in the container\n";
}

#endif // EASYFIND.HPP