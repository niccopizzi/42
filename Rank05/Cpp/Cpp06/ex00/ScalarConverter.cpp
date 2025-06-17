#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& scalarconverter)
{
    (void)scalarconverter;
    std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& scalarconverter)
{
    (void)scalarconverter;
    std::cout << "ScalarConverter Copy assignment operator called" << std::endl;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

void    displayChar(char c, bool convertible)
{
    if (!convertible || !isascii(c))
        std::cout << "impossible\n";
    else if (!isprint(c))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << c << "'\n";
}

void    convertChar(char c)
{
    std::cout << "char: ", displayChar(c, true);
    std::cout << "int: " << static_cast<int>(c) << '\n';
    std::cout << "float: " << static_cast<float>(c) << ".0f\n";
    std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

void    convertInt(std::string& literal)
{
    long   i;
    std::stringstream ss(literal);

    ss >> i;
    std::cout << "char: ", displayChar(static_cast<char>(i), i < (1 << 8));
    if (i < __INT_MAX__)
        std::cout << "int: " << i << '\n';
    else
        std::cout << "int: impossible\n";
    std::cout << "float: " << static_cast<float>(i) << ".0f\n";
    std::cout << "double: " << static_cast<double>(i) << ".0\n";
}

bool    isConvertible(double d)
{
    return (!std::isnan(d) && !std::isinf(d));
}

void    convertFloat(std::string& literal)
{
    float   f;
    std::stringstream ss(literal);

    if (literal == "+inff")
        f = std::numeric_limits<double>::infinity();
    else if (literal == "-inff")
        f = std::numeric_limits<double>::infinity() * -1;
    else if (literal == "nanf")
        f = std::numeric_limits<double>::quiet_NaN();
    else
        ss >> f;

    std::cout << "char: ", displayChar(f, isConvertible(f) && f < (1 << 8));
    if (isConvertible(f) && f < __INT_MAX__)
        std::cout << "int: " << static_cast<int>(f) << '\n';
    else    
        std::cout << "int: impossible\n";
    if ((static_cast<int>(f) - f ) == 0)
        std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << static_cast<double>(f) << '\n';
}


void    convertDouble(std::string& literal)
{
    double   d;
    std::stringstream ss(literal);

    if (literal == "+inf")
        d = std::numeric_limits<double>::infinity();
    else if (literal == "-inf")
        d = std::numeric_limits<double>::infinity() * -1;
    else if (literal == "nan")
        d = std::numeric_limits<double>::quiet_NaN();
    else
        ss >> d;
    
    std::cout << "char: ", displayChar(d, isConvertible(d) && d < (1 << 8));
    if (isConvertible(d) && d < __INT_MAX__)
        std::cout << "int: " << static_cast<int>(d) << '\n';
    else    
        std::cout << "int: impossible\n";
    if ((static_cast<int>(d) - d ) == 0)
        std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(d) << "f\n";
    std::cout << "double: " << d << '\n';
}


void    ScalarConverter::convert(std::string& literal)
{
    if (literal.size() == 1 && isalpha(literal.at(0)))
        convertChar(literal.at(0));
    else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        convertFloat(literal);
    else if (literal == "-inf" || literal == "+inf" || literal == "nan")
        convertDouble(literal);
    else if (literal.find('.') != literal.npos)
    {
        if (literal.find('f') != literal.npos)
            convertFloat(literal);
        else
            convertDouble(literal);
    }
    else
        convertInt(literal);
}