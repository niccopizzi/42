#include "Span.hpp"

Span::Span()
{
   // std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N)
{
    ar.reserve(N);
   // std::cout << "Integer constructor called\n";
}

Span::Span(const Span& span)
{
    ar = span.ar;
   // std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& span)
{
    if (this != &span)
    {
        if (ar.capacity() < span.ar.size())
            throw   std::length_error("Size of arrays does not match");
        ar = span.ar;
    }
    std::cout << "Span Copy assignment operator called" << std::endl;
    return (*this);
}

Span::~Span()
{
   // std::cout << "Span destructor called" << std::endl;
}

std::vector<int>::const_iterator    Span::begin() const
{
    return (ar.begin());
}

std::vector<int>::const_iterator    Span::end() const
{
    return (ar.end());
}

void    Span::addNumber(int num)
{
    if (ar.size() == ar.capacity())
        throw std::length_error("Max capacity reached, cannot add new elements");
    ar.push_back(num);
}

void    Span::addNumber(std::vector<int>::const_iterator begin, 
                        std::vector<int>::const_iterator end)
{
    if (end < begin)
        std::swap(begin, end);

    if (static_cast<unsigned int>(end - begin) > ar.capacity() - ar.size())
        throw std::length_error("Cannot add this amount of elements to the span");    
    std::copy(begin, end, std::back_inserter(ar));
}

int     Span::longestSpan() const
{
    if (ar.size() <= 1)
        throw std::length_error("Not enough elements to calculate span");
    return (*std::max_element(ar.begin(), ar.end()) - 
            *std::min_element(ar.begin(), ar.end()));
}

int     Span::shortestSpan() const
{
    if (ar.size() <= 1)
        throw std::length_error("Not enough elements to calculate span");

    std::vector<int> copy(ar);
    std::vector<int>::iterator  begin(copy.begin());
    std::vector<int>::iterator  end(copy.end());
    int              shortestDistance = __INT_MAX__;

    std::sort(begin, end);
  
    for (; begin != (end - 1); ++begin)
    {
        if ((*(begin + 1) - *begin) < shortestDistance)
            shortestDistance = *(begin + 1) - *begin;
    }
    return (shortestDistance);
}

std::ostream&   operator<<(std::ostream& os, const Span& sp)
{
    int index = 0;

    std::vector<int>::const_iterator it = sp.begin();
    std::vector<int>::const_iterator end = sp.end();

    for (; it != end; ++it)
    {
        os << "Element [" << index << "] : " << *it << "\n";  
        index++;
    }
    return (os);
}