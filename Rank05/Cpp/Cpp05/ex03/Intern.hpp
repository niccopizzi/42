#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequest.hpp"

class Intern
{
    private:
        static const std::string PossibleForms[3];
    public:
        Intern();
        Intern(const Intern& );
        Intern& operator=(const Intern& );
        ~Intern();

        AForm*  makeForm(const std::string& form, const std::string& target) const;
};


#endif // INTERN.HPP