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
    std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
void (Harl::*func[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};    
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level)
            (this->*func[i])();
    }
}
