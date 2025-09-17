#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), 
                                                            GradeTooHighException("Error : Grade is too high"), 
                                                            GradeTooLowException("Error : Grade is too low")
{
    if (grade < 1)
        throw (Bureaucrat::GradeTooHighException);
    if (grade > 150)
        throw  (Bureaucrat::GradeTooLowException);
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
        throw (Bureaucrat::GradeTooHighException);
    grade--;
}

void    Bureaucrat::downgrade()
{
    if (grade == 150)
        throw (Bureaucrat::GradeTooLowException);
    grade++;
}

void    Bureaucrat::signForm(Form& F) const
{
    try
    {
        F.beSigned(*this);
        std::cout << _name << " signed " << F.getName() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << _name << " couldn't sign " << F.getName() << " because "
        << e.what() << '\n';
    }
    
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    return (os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl);
}