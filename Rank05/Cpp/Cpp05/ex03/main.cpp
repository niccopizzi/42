#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main ()
{   
    Intern  someRandomIntern;
    AForm*  rrf;
    AForm*  notexist;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    notexist = someRandomIntern.makeForm("nonexistent form", "home");
    
    delete rrf;
    if (notexist != NULL)
    {
        std::cout << "notexist is something!\n";
        delete notexist;
    }
    return (0);
}