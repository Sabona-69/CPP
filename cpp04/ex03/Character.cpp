#include "Character.hpp"

Character:: Character(){
    for (int i = 0; i < 4; i++){
        this->inventory[i] = NULL;
        this->garbage[i] = NULL;
    }
    std::cout << "Default Character Constructor called !" << std::endl;
}

Character:: Character(const Character &assign) : name(assign.name) {
    for (int i = 0; i < 4; i++){
        this->inventory[i] = (assign.inventory[i] ? assign.inventory[i]->clone() : NULL);
        this->garbage[i] = this->inventory[i]; 
    }
    std::cout << "Character Copy Constructor called !" << std::endl;
}

Character:: Character(const std::string  &assign) : name(assign) {
    for (int i = 0; i < 4; i++){
        this->inventory[i] = NULL;
        this->garbage[i] = NULL;
    }
}

Character&   Character::operator=(const Character &assign){
    if(this != &assign){
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i])
                delete this->inventory[i];
            if (this->garbage[i])
                delete this->garbage[i],this->garbage[i] = NULL;
            this->inventory[i] = (assign.inventory[i] ? assign.inventory[i]->clone() : NULL);
        }
    }
}

Character::~Character() {
    for (int i = 0; i < 4; i++){
        delete this->inventory[i];
        // this->inventory[i] = NULL;
        delete this->garbage[i];
        // this->garbage[i] = NULL;
    }
    std::cout << "Default Character Destructor called !" << std::endl;
};

std::string const &Character::getName() const{
    return this->name;
}

void Character::equip(AMateria* m){
    for (int i = 0; i < 4; i++){
        if (!this->inventory[i])
            this->inventory[i] = m->clone();
    }
}

void Character::unequip(int idx){
    if (idx > 3 || idx < 0)
        return ;
    if (this->inventory[idx])
    {
        if (this->garbage[idx])
            delete this->garbage[idx];
        this->garbage[idx] = this->inventory[idx];
        this->inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target){
    if (idx > 3 || idx < 0)
        return ;
    if (this->inventory[idx])
        this->inventory[idx]->use(target);   
}