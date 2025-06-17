#include "RobotomyRequest.hpp"

inline unsigned char  invertBits(unsigned char x)
{
    return (((1 << 9) - 1) ^ x);
}

RobotomyRequest::RobotomyRequest(const std::string& target) : AForm("Robotomy Request", 72, 45) , _target(target)
{
   // std::cout << "Robotomy Request created\n";
} 

RobotomyRequest::~RobotomyRequest() throw()
{
   // std::cout << "Robotomy Request canceled\n";
}

void    RobotomyRequest::drill() const
{
    std::fstream    iof((_target + "_shrubbery").c_str());
    std::string     line;
    std::string     newLine;

    if (iof.bad() || rand() % 2 )
    {
        std::cout << "Robotomy failed, try again!\n";
        return ;
    }
    while (getline(iof, line))
    {
        for (std::string::iterator it = line.begin(); it != line.end(); ++it)
            newLine += invertBits(*it);
        iof << newLine << '\n';
    }
    std::cout << "Success! The drill is complete\n";
}

void    RobotomyRequest::execute(Bureaucrat const & executor) const
{
    try
    {
        AForm::execute(executor);
        drill();
    }
    catch(const std::exception& e)
    {
        std::cerr << "An error occurred while drilling the tree : " << e.what() << '\n';
    }
    
}