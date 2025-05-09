#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        ideas[i] = "";
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& brain)
{
    for (unsigned int i = 0; !brain.ideas[i].empty(); i++)
        ideas[i] = brain.ideas[i];
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& brain)
{

    for (unsigned int i = 0; !brain.ideas[i].empty(); i++)
        ideas[i] = brain.ideas[i];
    std::cout << "Brain Copy assignment operator called" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

const std::string&    Brain::getIdeas(unsigned int index) const 
{
    if (index < 0 || index > 100)
        throw std::out_of_range("Index out of range");
    return (ideas[index]);
}

void    Brain::setIdeas(unsigned int index, const std::string& newIdea) 
{
    if (index >= 0 && index < 100)
        ideas[index] = newIdea;
}