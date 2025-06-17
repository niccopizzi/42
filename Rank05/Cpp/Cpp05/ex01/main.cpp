#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{   
    Form    f("SUPERIMPORTANT PRACTICE", 20, 5);

    std::cout << f;

    Bureaucrat  b("MEGADIRECTOR", 1);
    Bureaucrat  c("Fantozzi", 120);

    b.signForm(f);
    std::cout << f;
    c.signForm(f);

    try
    {
        Form g("not very important", 160, 160);

        std::cout << g;
    }
    catch(const std::exception& e)
    {
        std::cerr << "An error occured : " << e.what() << '\n';
    }
    
    return (0);
}