#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
    std::cout << "Default Bureaucrat Constructor called !" << std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Default Bureaucrat Destructor called !" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &assign){
    std::cout << "Bureaucrat Copy Constructor called !" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &assign){
    if (this != &assign){
        // Assignment logic here
    }
    return *this;
}
