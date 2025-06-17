#include "easyfind.hpp"

int main(void)
{
    srand(time(0));
    std::vector<int> v;

    for (int i = 0; i < 10; i++)
        v.push_back(rand());

    v.push_back(2);
    easyfind(v, 2);
    return (0);
}