#include "Brain.hpp"

Brain::Brain(){
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "idea !!";
    std::cout << "Constructor Brain called !" << std::endl;
}
    
Brain::~Brain(){
    std::cout << "Destructor Brain called !" << std::endl;
}

Brain::Brain(const Brain &assign){
    for (int i = 0; i < 100; i++){
        this->ideas[i] = assign.ideas[i];
    }
    std::cout << "Copy Constructor called !" << std::endl;
}

Brain&   Brain::operator=(const Brain &assign){
    if (this != &assign){
        for (int i = 0; i < 100; i++){
            this->ideas[i] = assign.ideas[i];
        }
    }
    return *this;
}

