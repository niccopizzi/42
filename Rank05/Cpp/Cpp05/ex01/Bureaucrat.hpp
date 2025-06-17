#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

//Forward declaration

class Form;

class Bureaucrat : public std::exception
{
    private:
        const std::string       _name;
        const std::out_of_range GradeTooHighException;
        const std::out_of_range GradeTooLowException;
        int                     grade;
        Bureaucrat();
    public:
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat(void) throw(); /*Destructor*/

        const   std::string getName() const;
        int                 getGrade() const;
        void                promote();
        void                downgrade();
        void                signForm(Form& F) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif // BUREAUCRAT.HPP


