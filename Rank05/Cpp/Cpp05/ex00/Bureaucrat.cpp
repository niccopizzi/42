#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), GradeTooHighException("Error : Grade is too high"), GradeTooLowException("Error : Grade is too low")
{
    if (grade < 1)
        throw GradeTooHighException;
    if (grade > 150)
        throw  GradeTooLowException;
    this->grade = grade;
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void) throw()
{
    std::cout << "Default destructor called\n";
}

const std::string Bureaucrat::getName() const
{
    return(_name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

void    Bureaucrat::promote() 
{
    if (grade == 1)
        throw GradeTooHighException;
    grade ++;
}

void    Bureaucrat::downgrade()
{
    if (grade == 150)
        throw GradeTooLowException;
    grade --;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    return (os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl);
}