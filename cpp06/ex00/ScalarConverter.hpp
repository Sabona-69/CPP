#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>

class ScalarConverter {
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &assign);
    ScalarConverter& operator=(const ScalarConverter &assign);
    public:
        static void convert(std::string input);
};

#endif
