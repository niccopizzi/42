#ifndef ROBOTOMYREQUEST_HPP
#define ROBOTOMYREQUEST_HPP

#include "AForm.hpp"

class RobotomyRequest : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequest(const std::string& target);
        ~RobotomyRequest() throw();

        void    execute(Bureaucrat const & executor) const;
        void    drill(void) const;
};



#endif // ROBOTOMYREQUEST.HPP