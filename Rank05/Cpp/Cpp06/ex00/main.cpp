#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    std::string s(argv[1]);

    if (argc > 1)
        ScalarConverter::convert(s);
    else
        std::cout << "Please insert string literal to convert\n";
    return (0);
}