#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main ()
{   
    Intern  someRandomIntern;
    AForm*  robotomyForm;
    AForm*  presPardForm;
    AForm*  shrubbForm;
    AForm*  notexist;

    robotomyForm = someRandomIntern.makeForm("robotomy request", "Bender");
    presPardForm = someRandomIntern.makeForm("presidential pardon", "Bender");
    shrubbForm = someRandomIntern.makeForm("shrubbery creation", "Bender");
    notexist = someRandomIntern.makeForm("nonexistent form", "home");
    
    delete robotomyForm;
    delete shrubbForm;
    delete presPardForm;
    if (notexist != NULL)
    {
        std::cout << "notexist is something!\n";
        delete notexist;
    }
    return (0);
}