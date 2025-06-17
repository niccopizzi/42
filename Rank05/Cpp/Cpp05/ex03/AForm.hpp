#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <cstdlib>

//Forward declaration
class Bureaucrat;

class AForm : virtual public std::exception
{
    private:
        const std::string       _name;
        bool                    _signed;
        const int               gradeToSign;
        const int               gradeToExecute;
        const std::out_of_range GradeTooHighException;
        const std::out_of_range GradeTooLowException;
        const std::logic_error  FormNotSignedException;

    public:
        AForm(const std::string& name, int signGrade, int executeGrade);
        virtual ~AForm(void) throw() = 0; /*Destructor*/

        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;
        const std::string&  getName() const;  
        bool                getSigned() const;

        void                beSigned(Bureaucrat const & signer);
        virtual void        execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& Form);

#endif // FORM.HPP