#include "Brain.hpp"

Brain::Brain()
{
    ideasNum = 0;
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& brain)
{
    const std::string* ptr = brain.getIdeas();

    for (unsigned int i = 0; i < brain.getIdeasNum(); i++)
        this->ideas[i] = std::string(ptr[i]);
    this->ideasNum = brain.getIdeasNum();
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& brain)
{
    const std::string* ptr = brain.getIdeas();

    for (unsigned int i = 0; i < brain.getIdeasNum(); i++)
        this->ideas[i] = std::string(ptr[i]);
    this->ideasNum = brain.getIdeasNum();
    std::cout << "Brain Copy assignment operator called" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

const std::string*    Brain::getIdeas() const 
{
    return (ideas);
}

unsigned int    Brain::getIdeasNum() const
{
    return (ideasNum);
}