#include "Zombie.hpp"

Zombie::Zombie(){
}

Zombie::~Zombie(){
    std::cout << name << ":  Destrooooyed ..." << std::endl;
}

void    Zombie::set_name(std::string new_name){
    name = new_name;
}

void    Zombie::announce(){
    std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
