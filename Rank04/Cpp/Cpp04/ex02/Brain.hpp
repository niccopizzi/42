#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string     ideas[100];
    public:
        Brain(); /*Constructor*/
        Brain(const Brain& ); /*Copy constructor*/
        Brain& operator=(const Brain& ); /*Copy assignment operator*/
        ~Brain(void); /*Destructor*/

        const std::string&    getIdeas(unsigned int index) const; 
        void                  setIdeas(unsigned int index, const std::string& newIdea);
};

#endif // BRAIN.HPP