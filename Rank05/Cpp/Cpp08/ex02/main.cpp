#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>


int main(void)
{
    {
        std::cout << "Expected output\n/******************************/\n";
        std::list<int>    mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);


        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mstack);
        std::cout << "/******************************/";
    }
    {    
        std::cout << "\nGot\n/******************************/\n";
        MutantStack<double>    mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);


        MutantStack<double>::iterator it = mstack.begin();
        MutantStack<double>::iterator ite = mstack.end();
        
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<double> s(mstack);
        std::cout << "/******************************/\n";
    }
    return (0);
}
