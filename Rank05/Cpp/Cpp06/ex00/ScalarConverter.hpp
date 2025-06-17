#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter(); 
    public:
        ScalarConverter(const ScalarConverter& );
        ScalarConverter& operator=(const ScalarConverter& );
        ~ScalarConverter();

        static  void    convert(std::string& literal);
};

#endif // SCALARCONVERTER.HPP