#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
    std::cout << "Default ScalarConverter Constructor called !" << std::endl;
}

ScalarConverter::~ScalarConverter(){
    std::cout << "Default ScalarConverter Destructor called !" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &assign){
    (void)assign;
    std::cout << "ScalarConverter Copy Constructor called !" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &assign){
    if (this != &assign){
        (void)assign;
        // Assignment logic here
    }
    return *this;
}

#define CHAR    0
#define INT     1
#define DOUBLE  2
#define FLOAT   3

static bool checkInf(const std::string& input) {
    if (input == "nan" || input == "nanf" ||
        input == "-inff" || input == "+inff" ||
        input == "-inf" || input == "+inf")
    {
        bool neg = (input[0] == '-');
        bool isNan = (input.find("nan") != std::string::npos);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (isNan)
        std::cout << "float: nanf\n";
        else
        std::cout << "float: " << (neg ? "-inff\n" : "+inff\n");
        if (isNan)
        std::cout << "double: nan\n";
        else
        std::cout << "double: " << (neg ? "-inf\n" : "+inf\n");
        return true;
    }
    return false;
}


static int     parseInput(std::string input){
    int countF = 0;
    int countDots = 0;
    for (size_t i = 0; i < input.size(); i++){
        if (!isdigit(input.at(i)) && 
            input.at(i) != '.' && input.at(i) != 'f' && 
            input.at(i) != '+' && input.at(i) != '-')
            {
                throw 42;
            }
        if (i && (input.at(i) == '+' || input.at(i) == '-'))
            throw 42;
        if (input.at(i) == '.')
            countDots++;
        if (input.at(i) == 'f')
            countF++;
        if (countF > 1 || countDots > 1)
            throw 42;
    }
    if (countF && input.at(input.length() - 1) != 'f')
        throw 42;
    if (countDots && (input.at(input.length() - 1) == '.' || input.at(0) == '.'))
        throw 42;
    float checkChar = atof(input.c_str());
    if (checkChar == static_cast<int>(checkChar) && checkChar >= 0 && checkChar <= 255)
        return CHAR;
    if (countF)
        return FLOAT;
    if (countDots)
        return DOUBLE;
    return INT;
}

static void printAll(char c, int i, float f, double d){
    std::string printChar;
    std::string printZero = d == static_cast<int>(d) ? ".0" : "";
    if (i < 0 || i > 255)
        printChar = "impossible";
    else {
        if (!isgraph(c))
            printChar = "Non displayable";
        else
        printChar = std::string("'") + (char)c + "'";
    }
    std::cout << "char: " << printChar << std::endl;
    std::cout << "int: "  << i << std::endl;
    std::cout << "float: " << f << printZero << "f" << std::endl;
    std::cout << "double: " << d << printZero << std::endl;
}



void ScalarConverter::convert(std::string input){
    
    if (checkInf(input))
        return ;
    int flag;
    try{
        flag = parseInput(input);
    }
    catch( ... )
    {
        std::cout << "Invalid Input ! \n";
        return ;
    }
    int i;
    unsigned char c;
    float f;
    double d;
    switch (flag) {
        case CHAR: {
            c = std::atoi(input.c_str());
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break;
        }
        case INT: {
            i = std::atoi(input.c_str());
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            break;
        }
        case FLOAT: {
            f = static_cast<float>(std::atof(input.c_str()));
            c = static_cast<char>(f);
            i = static_cast<int>(f);
            d = static_cast<double>(f);
            break;
        }
        case DOUBLE: {
            d = std::atof(input.c_str());
            c = static_cast<char>(d);
            i = static_cast<int>(d);
            f = static_cast<float>(d);
            break;
        }
    }
    printAll(c, i, f, d);
}
