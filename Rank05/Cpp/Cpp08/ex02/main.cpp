#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
    {
        std::cout << "Expected output\n/******************************/\n";
        std::list<int>    list;
        list.push_back(5);
        list.push_back(17);
        std::cout << list.back() << std::endl;
        list.pop_back();
        std::cout << list.size() << std::endl;
        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
        list.push_back(0);


        std::list<int>::iterator it = list.begin();
        std::list<int>::iterator ite = list.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout << "/******************************/";
    }
    {    
        std::cout << "\nGot\n/******************************/\n";
        MutantStack<int>    mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);


        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
        std::cout << "/******************************/\n";
    }

    {
        std::cout << "Expected output\n/******************************/\n";
        std::list<int>    list;

        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        list.push_back(4);
        list.push_back(5);

        std::list<int>::reverse_iterator rit = list.rbegin();
        std::list<int>::reverse_iterator rite = list.rend();

        ++rit;
        --rit;
        while (rit != rite)
        {
            std::cout << *rit << "\n";
            ++rit;
        }
        std::cout << "/******************************/";

    }

    {
        std::cout << "\nGot\n/******************************/\n";
        MutantStack<int>    mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);

        mstack.push(6);
        mstack.pop();

        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::reverse_iterator rite = mstack.rend();
        
        ++rit;
        --rit;
        while (rit != rite)
        {
            std::cout << *rit << "\n";
            ++rit;
        }
        std::cout << "/******************************/\n";
    }

    {
        MutantStack<int>    empty_stack;

        empty_stack.empty() ? std::cout << "Empty\n" : std::cout << "Not empty\n";

        MutantStack<int>::iterator          it = empty_stack.begin();

        if (it != empty_stack.end())
            std::cout << "Error\n";
        MutantStack<int>::reverse_iterator rit = empty_stack.rbegin();
        if (rit != empty_stack.rend())
            std::cout << "Error\n";
    }
    return (0);
}