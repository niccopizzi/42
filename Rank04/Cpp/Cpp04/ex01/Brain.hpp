#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string     ideas[100];
        unsigned int    ideasNum;
    public:
        Brain(); /*Constructor*/
        Brain(const Brain& ); /*Copy constructor*/
        Brain& operator=(const Brain& ); /*Copy assignment operator*/
        ~Brain(void); /*Destructor*/

        const std::string*    getIdeas() const; 
        unsigned int          getIdeasNum() const;
};

#endif // BRAIN.HPP