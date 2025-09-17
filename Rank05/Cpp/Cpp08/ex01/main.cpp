#include <vector>
#include <iostream>
#include <ctime>
#include "Span.hpp"

int main()
{
    std::srand(unsigned(std::time(NULL)));

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    

    std::vector<int> v(30000);
    std::generate(v.begin(), v.end(), std::rand);
    
    Span    sp2 = Span(30000);
    sp2.addNumber(v.begin(), v.end());
    std::cout << sp2;
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    return 0;
} 