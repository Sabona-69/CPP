#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Constructor Brain called !" << std::endl;
}
    
Brain::~Brain(){
    std::cout << "Destructor Brain called !" << std::endl;
}
    
// Brain::Brain(const Brain &assign){
// }
    
Brain&   Brain::operator=(const Brain &assign){
    if (this != &assign){
    }
    return *this;
}



