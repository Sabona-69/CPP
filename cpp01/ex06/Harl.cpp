#include "Harl.hpp"

void Harl::debug() { std::cout << "Debugging !" << std::endl; }

void Harl::info() { std::cout << "Some info here !" << std::endl; }

void Harl::warning() {
  std::cout << "Carefull this is a warning !" << std::endl;
}

void Harl::error() { std::cout << "ERROR !" << std::endl; }

void Harl::complain(std::string level) {
  std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  int index = -1;
  void (Harl::*func[])() = {&Harl::debug, &Harl::info, &Harl::warning,
                            &Harl::error};
  for (int i = 0; i < 4; i++) {
    if (levels[i] == level)
      index = i;
  }
//  for (int i = index; i < 4; i++) {
    switch (index) {
    case 0: {
      (this->*func[0])();
      __attribute__((fallthrough));
    }
    case 1: {
      (this->*func[1])();
      __attribute__((fallthrough));
    }
    case 2: {
      (this->*func[2])();
      __attribute__((fallthrough));
    }
    case 3: {
      (this->*func[3])();
      break;
    }
    default: {
      std::cout << "[ Probably complaining about insignificant problems ]"
                << std::endl;
    }
   // }
  }
}
