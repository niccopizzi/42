#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(const std::string& name, int signGrade, int executeGrade) : _name(name), gradeToSign(signGrade), gradeToExecute(executeGrade),
GradeTooHighException("The grade is too high"), GradeTooLowException("The grade is too low"), FormNotSignedException("The form is not signed")
{
    _signed = false;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException;
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException;
    std::cout << "Form constructor called, everything seems to be ok!\n"; 
}

AForm::~AForm() throw()
{
    std::cout << "Form destructor called\n";
}

void    AForm::beSigned(const Bureaucrat& B)
{
    int     BGrade = B.getGrade();

    if (BGrade > gradeToSign)
        throw GradeTooLowException;
    _signed = true;   
}

void    AForm::execute(Bureaucrat const & executor) const
{
    if (!_signed)
        throw FormNotSignedException;
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException;
}

const std::string& AForm::getName() const
{
    return (_name);
}

int     AForm::getGradeToSign() const
{
    return (gradeToSign);
}

int     AForm::getGradeToExecute() const
{
    return (gradeToExecute);
}

bool    AForm::getSigned() const
{
    return (_signed);
}

std::ostream& operator<<(std::ostream& os, const AForm& F)
{
    const std::string sign = F.getSigned() ? "Signed\n" : "Unsigned\n"; 

    return (os << "Form name : " << F.getName() << "\n"
            << sign << "Grade required to sign    : " << F.getGradeToSign()
            << "\nGrade required to execute : " << F.getGradeToExecute() << "\n");
}