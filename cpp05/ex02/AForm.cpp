#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), execGrade(1), signGrade(1) {
    std::cout << "Default AForm Constructor called !" << std::endl;
}

AForm::~AForm(){
    std::cout << "Default AForm Destructor called !" << std::endl;
}

AForm::AForm(const AForm &assign) :
name(assign.name), isSigned(assign.isSigned),  execGrade(assign.execGrade), signGrade(assign.signGrade){
    std::cout << "AForm Copy Constructor called !" << std::endl;
}

AForm::AForm(std::string name, int execGrade, int signGrade) : name(name), isSigned(false), execGrade(execGrade), signGrade(signGrade) {
    if (this->execGrade > 150 || this->signGrade > 150)
        throw AForm::GradeTooLowException();
    else if (this->execGrade < 1 || this->signGrade < 1)
        throw AForm::GradeTooHighException();
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

const char* AForm::GradeNotSignedException::what() const throw() {
    return "Grade : Not Signed !!";
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade : Too high !!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade : Too low !!";
}

std::ostream&    operator<<(std::ostream& os, const AForm& obj){
    std::string str =  obj.getIsSigned() ? "signed" : "not signed";
    return os << obj.getName() << " [" << str 
              << "], execution grade : " << obj.getExecGrade() << " and sign grade : "
              << obj.getSignGrade();
}

void        AForm::beSigned(Bureaucrat& obj){
    if (obj.getGrade() > this->signGrade){
        std::cout << obj.getName() << " couldn't sign " << this->name << " because the grade is too low !\n"; 
        throw AForm::GradeTooLowException();
    }
    std::cout << obj.getName() << " signed " << this->name << std::endl; 
    isSigned = true;
}
