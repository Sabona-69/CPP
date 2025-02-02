#include "Harl.hpp"

void Harl::debug() { 
	std::cout << "{ DEBUG }\nDebugging !\n" << std::endl;
}

void Harl::info() {
	 std::cout << "{ INFO }\nSome info here !\n" << std::endl;
}

void Harl::warning() {
	std::cout << "{ WARNING }\nCarefull this is a warning !\n" << std::endl;
}

void Harl::error() {
	std::cout << "{ ERROR }\n This is unacceptable! I want to speak to the manager now !\n" << std::endl;
}

void Harl::complain(std::string level) {
	int count = (level == "DEBUG") + (level == "INFO") * 2 + (level == "WARNING") * 3 + (level == "ERROR") * 4;
	switch (count) {
    case 1:
      debug();
      // fallthrough
    case 2:
      info();
      // fallthrough
    case 3:
      warning();
      // fallthrough
    case 4:
      error();
      // fallthrough
	  break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
  }
}
