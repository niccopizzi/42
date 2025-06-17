#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Span
{
    private:
        std::vector<int>    ar;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& ); 
        Span& operator=(const Span& );
        ~Span();

        std::vector<int>::const_iterator    begin() const;
        std::vector<int>::const_iterator    end() const;
        void    addNumber(int num);
        void    addNumber(
                    std::vector<int>::const_iterator begin, 
                    std::vector<int>::const_iterator end);
        int     shortestSpan() const;
        int     longestSpan() const;
};

std::ostream&   operator<<(std::ostream& os, const Span& sp);

#endif // SPAN.HPP