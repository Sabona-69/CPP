#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), execGrade(0), signGrade(0) {
    std::cout << "Default AForm Constructor called !" << std::endl;
}

AForm::~AForm(){
    std::cout << "Default AForm Destructor called !" << std::endl;
}

AForm::AForm(const AForm &assign) :
    name(assign.name), isSigned(assign.isSigned), execGrade(assign.execGrade), signGrade(assign.signGrade){
    std::cout << "AForm Copy Constructor called !" << std::endl;
}

AForm& AForm::operator=(const AForm &assign){
    if (this != &assign){
        this->isSigned = assign.isSigned;
    }
    return *this;
}

std::string AForm::getName() const {
    return this->name;
}

bool    AForm::getIsSigned() const {
    return this->isSigned;
}

int AForm::getExecGrade() const {
    return this->execGrade;
}

int AForm::getSignGrade() const {
    return this->signGrade;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade : Too high !!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade : Too Low !!";
}

std::ostream&    operator<<(std::ostream& os, const AForm& obj){
    return os << obj.getName() << ", the sign is : " << obj.getIsSigned() 
              << " , execution grade : " << obj.getExecGrade() << " and sign grade : "
              << obj.getSignGrade() << std::endl;
}

void        AForm::beSigned(Bureaucrat& obj){
    if (obj.getGrade() < 1 || obj.getGrade() > 150){
        std::cout << obj.getName() << " couldn't sign " << this->name << "because " ; 
        obj.getGrade() < 1 ? throw AForm::GradeTooHighException() : throw AForm::GradeTooLowException();
    }
    std::cout << obj.getName() << " signed " << this->name << std::endl; 
    isSigned = true;
}
