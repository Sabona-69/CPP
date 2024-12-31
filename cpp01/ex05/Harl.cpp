#include "Harl.hpp"

void    Harl::debug(){
   std::cout << "Debugging !" << std::endl;
}

void    Harl::info(){
   std::cout << "Some info here !" << std::endl;
}

void    Harl::warning(){
   std::cout << "Carefull this is a warning !" << std::endl;
}

void    Harl::error(){
   std::cout << "ERROR !" << std::endl;
}

void    Harl::complain(std::string level)
{
    switch (!level.empty())
    {
        case  level == "debug":
            debug();
        case  level == "info":
            info();
        case  level == "warning":
            warning();
        case  level == "error":
            error();
        default
            std::cout << "invalid log level" std::endl;
    }
}