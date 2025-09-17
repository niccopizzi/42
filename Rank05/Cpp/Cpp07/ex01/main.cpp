#include "iter.hpp"
#include <iostream>

template<typename T>
void    addTen(T& elem)
{
    elem += 10;
}

template<typename T>
void    printElem(const T& elem)
{
    std::cout << elem << '\n';
}

void    deleteDoubles(std::string& n)
{
    bool map[256] = {0};

    for (std::string::iterator it = n.begin(); it != n.end(); )
    {
        if (map[static_cast<unsigned char>(*it)])
        {
            it = n.erase(it);
        }
        else
        {
            map[static_cast<unsigned char>(*it)] = true;
            it++;
        }
    }
}

int main(void)
{
    {
        int array[10] = {0};

        std::cout << "Array before iter\n";
        for(int i = 0; i < 10; i++)
            std::cout << array[i] << "\n";
        iter(array, 10, addTen);
        std::cout << "Array after iter\n";
        for(int i = 0; i < 10; i++)
            std::cout << array[i] << "\n";
    }
    {
        float fArray[10] = {5.0, 2.2, 3.5, 1.0, 8.8,
                            4.4, 5.6, 1.2, 1.1, 6.6};

        std::cout << "Array before iter\n";
        for(int i = 0; i < 10; i++)
            std::cout << fArray[i] << "\n";
        iter(fArray, 10, addTen);
        std::cout << "Array after iter\n";
        for(int i = 0; i < 10; i++)
            std::cout << fArray[i] << "\n";
    }
    {
        std::string array[5] = {"Abba", "Lamba", "Gamma", "Samba", "Rumbabbbba"};
        std::cout << "Strings before removing doubles\n";
        for(int i = 0; i < 5; i++)
            std::cout << array[i] << "\n";
        iter(array, 5 , deleteDoubles);
        std::cout << "Strings after removing doubles\n";
        for(int i = 0; i < 5; i++)
            std::cout << array[i] << "\n";
    }

    {
        const int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::cout<<"Printing the const array of ints\n";
        iter(array, 10, printElem<const int>);

        std::cout<<"Printing the const array of strings\n";
        const std::string strArray[8] = {"This", "is", "a", "test", "for", "iter", "on", "const"};
        iter(strArray, 8, printElem<const std::string&>);
    }
    return (0);
}