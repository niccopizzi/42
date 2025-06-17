#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(const std::string& name, int signGrade, int executeGrade) : _name(name), gradeToSign(signGrade), gradeToExecute(executeGrade),
GradeTooHighException("The grade is too high"), GradeTooLowException("The grade is too low")
{
    _signed = false;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException;
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException;
    std::cout << "Form constructor called, everything seems to be ok!\n"; 
}

Form::~Form() throw()
{
    std::cout << "Form destructor called\n";
}

void    Form::beSigned(const Bureaucrat& B)
{
    int     BGrade = B.getGrade();

    if (BGrade > gradeToSign)
        throw GradeTooLowException;
    _signed = true;   
}

const std::string& Form::getName() const
{
    return (_name);
}

int     Form::getGradeToSign() const
{
    return (gradeToSign);
}

int     Form::getGradeToExecute() const
{
    return (gradeToExecute);
}

bool    Form::getSigned() const
{
    return (_signed);
}

std::ostream& operator<<(std::ostream& os, const Form& F)
{
    const std::string sign = F.getSigned() ? "Signed\n" : "Unsigned\n"; 

    return (os << "Form name : " << F.getName() << "\n"
            << sign << "Grade required to sign    : " << F.getGradeToSign()
            << "\nGrade required to execute : " << F.getGradeToExecute() << "\n");
}