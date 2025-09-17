#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequest.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{   
    Bureaucrat                  b("MegaDirector Galactic", 1);
    Bureaucrat                  fan("Fantozzi", 150);
    ShrubberyCreationForm       sf("new");
    RobotomyRequest             rf("new");
    PresidentialPardonForm      pf("home");

    srand(time(0));
    try
    {
        sf.beSigned(fan);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error while signing the form : " << e.what() << '\n';
    }
    sf.beSigned(b);
    sf.execute(b);

    rf.beSigned(b);
    rf.execute(fan);
    rf.execute(b);
    try
    {
        pf.beSigned(fan);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error while signing the form : " << e.what() << '\n';
    }
    pf.execute(b);
    return (0);
}