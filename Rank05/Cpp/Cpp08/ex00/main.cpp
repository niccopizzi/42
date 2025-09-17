#include "easyfind.hpp"
#include <set>

int main(void)
{
    srand(time(0));
    std::vector<int> v;
    std::set<int> s;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(rand() % 100);
        s.insert(rand() % 100);
    }

    s.insert(2);
    v.push_back(2);
    try 
    {
        easyfind<std::vector<int> >(v, 2);
        easyfind<const std::set<int> >(s, 2);
        easyfind(v, -10);
    }
    catch(const std::exception& e) 
    {
        std::cerr << e.what() << '\n';
    }

    try 
    {
        easyfind(s, -10);
    }
    catch(const std::exception& e) 
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}