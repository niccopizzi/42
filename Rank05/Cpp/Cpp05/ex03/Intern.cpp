#include "Intern.hpp"

const std::string Intern::PossibleForms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& intern)
{
    (void)intern;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& intern)
{
    (void)intern;
    std::cout << "Intern Copy assignment operator called" << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm*  Intern::makeForm(const std::string& form, const std::string& target) const
{
    int index = 0; 

    for (; index < 3 && PossibleForms[index] != form; index ++)
        ;
    switch (index)
    {
    case 0:
        return (new ShrubberyCreationForm(target));
    case 1:
        return (new RobotomyRequest(target));
    case 2:
        return (new PresidentialPardonForm(target));
    default:
        std::cout << "Sorry " << form << " not available\n";
        return (NULL);
    }
}