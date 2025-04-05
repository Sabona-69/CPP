#include "ScalarConverter.hpp"

int main(int ac, char const *av[])
{
    if (ac != 2 || av[1][0] == '\0'){
        std::cout << "Invalid arguments !" << std::endl; 
        return 1;
    }
    std::string input = av[1];
    ScalarConverter::convert(input);
    return 0;
}
