#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), target("Default target"){
    std::cout << "Default PresidentialPardonForm Constructor called !" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Default PresidentialPardonForm Destructor called !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &assign) :  AForm(assign), target(assign.target){
    std::cout << "PresidentialPardonForm Copy Constructor called !" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &assign){
    if (this != &assign){
        this->target = assign.target;
        AForm::operator=(assign);
    }
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 5, 25), target(target) {
}

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const{
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    if (!this->getIsSigned())
        throw AForm::GradeNotSignedException();
    std::cout << this->target <<  " has been pardoned by Zaphod Beeblebrox\n";
}


