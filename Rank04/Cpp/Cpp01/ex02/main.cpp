#include <iostream>

int main(void)
{
    std::string str ("HI THIS IS BRAIN");

    std::string* strptr = &str;

    std::string& strref = str;

    std::cout << "Memory address of str              : " << &str << "\n";
    std::cout << "Memory address held by stringPTR   : " << strptr << "\n";
    std::cout << "Memory address held by stringREF   : " << &strref << "\n";
    std::cout << std::endl;
    std::cout << "Value of str                      :" << str << "\n";
    std::cout << "Value pointed to by stringPTR     :" << *strptr << "\n";
    std::cout << "Value pointed to by stringREF     :" << strref << "\n";
    return (0);
}