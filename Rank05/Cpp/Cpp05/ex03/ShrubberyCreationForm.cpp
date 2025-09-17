#include "ShrubberyCreationForm.hpp"

const char* assets[] = {"./assets/tree.txt", "./assets/tree2.txt", "./assets/tree3.txt"};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :   AForm("ShrubberyCreationForm", 145, 137), 
                                                                            _target(target)
{
    std::cout << "Shrubbery Creation Form created!\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() throw()
{
    std::cout << "ShrubberyCreationForm canceled\n";
}

void    ShrubberyCreationForm::plantTree(void) const
{
    std::ifstream   inf(assets[rand() % 3]);
    std::ofstream   outf((_target + "_shrubbery").c_str());
    std::string     line;
    
    if (inf.bad() || outf.bad())
    {
        std::cout << "Error in planting the tree\n";
        return ;
    }
    std::cout << "Planting the tree..\n";
    while (getline(inf, line))
        outf << line << "\n";
    std::cout << "Tree planted!\n";        
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    try
    {
        AForm::execute(executor);
        plantTree();
    }
    catch(const std::exception& e)
    {
        std::cerr << "An error occured while planting the tree : " << e.what() << '\n';
    }
}