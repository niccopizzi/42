#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{

    if (argc > 1)
    {
        std::string s(argv[1]);
        ScalarConverter::convert(s);
    }
    else
        std::cout << "Please insert string literal to convert\n";
    return (0);
}