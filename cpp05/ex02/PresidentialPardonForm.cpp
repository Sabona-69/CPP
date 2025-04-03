#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : target("Default target") {
    std::cout << "Default PresidentialPardonForm Constructor called !" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Default PresidentialPardonForm Destructor called !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &assign) : target(assign.target){
    std::cout << "PresidentialPardonForm Copy Constructor called !" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &assign){
    if (this != &assign){
        this->target = assign.target;
    }
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : target(target){
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor){

// executor.
    if (executor->getSignGrade() == 25 && executor->getExecGrade() == 5)
    {
        std::cout << this. target <<  " has been pardoned by Zaphod Beeblebrox\n";
    }
}


