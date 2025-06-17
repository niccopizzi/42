#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

//Forward declaration
class Bureaucrat;

class Form : public std::exception
{
    private:
        const std::string       _name;
        bool                    _signed;
        const int               gradeToSign;
        const int               gradeToExecute;
        const std::out_of_range GradeTooHighException;
        const std::out_of_range GradeTooLowException;

    public:
        Form(const std::string& name, int signGrade, int executeGrade);
        ~Form(void) throw(); /*Destructor*/

        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;
        const std::string&  getName() const;  
        bool                getSigned() const;

        void                beSigned(const Bureaucrat& B);
};

std::ostream& operator<<(std::ostream& os, const Form& Form);

#endif // FORM.HPP