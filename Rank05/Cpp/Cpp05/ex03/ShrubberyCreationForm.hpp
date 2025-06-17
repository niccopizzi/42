#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
        
    public:
        ShrubberyCreationForm(const std::string& target);
        ~ShrubberyCreationForm() throw();

        void    execute(Bureaucrat const& executor) const;
        void    plantTree(void) const;
};

#endif // SHRUBBERYCREATIONFORM.HPP