#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
    std::cout << "Default PresidentialPardonForm Constructor called !" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Default PresidentialPardonForm Destructor called !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &assign) : AForm(assign){
    std::cout << "PresidentialPardonForm Copy Constructor called !" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &assign){
    if (this != &assign){
        AForm::operator=(assign);
    }
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const AForm &obj) {
    if (obj.getSignGrade() == 25 && obj.getExecGrade() == 5)
    {
        std::cout << obj.getName() <<  "has been pardoned by Zaphod Beeblebrox\n";
    }
}
