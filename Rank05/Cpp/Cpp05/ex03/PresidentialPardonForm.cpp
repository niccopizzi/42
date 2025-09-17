#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", 25, 5), 
                                                                            _target(target)
{
    std::cout << "Presidential Pardon Form created\n";
}

PresidentialPardonForm::~PresidentialPardonForm() throw()
{
    std::cout << "Presidential Pardon Form canceled\n";
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    try
    {
        AForm::execute(executor);
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "An error occured while pardoning " << _target << " : " << e.what() << '\n';
    }
}