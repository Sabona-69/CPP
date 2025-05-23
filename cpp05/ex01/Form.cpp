#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), execGrade(1), signGrade(1) {
    std::cout << "Default Form Constructor called !" << std::endl;
}

Form::~Form(){
    std::cout << "Default Form Destructor called !" << std::endl;
}

Form::Form(const Form &assign) :
name(assign.name), isSigned(assign.isSigned),  execGrade(assign.execGrade), signGrade(assign.signGrade){
    std::cout << "Form Copy Constructor called !" << std::endl;
}

Form::Form(std::string name, int execGrade, int signGrade) : name(name), isSigned(false), execGrade(execGrade), signGrade(signGrade) {
    if (this->execGrade > 150 || this->signGrade > 150)
        throw Form::GradeTooLowException();
    else if (this->execGrade < 1 || this->signGrade < 1)
        throw Form::GradeTooHighException();
}

Form& Form::operator=(const Form &assign){
    if (this != &assign){
        this->isSigned = assign.isSigned;
    }
    return *this;
}

std::string Form::getName() const {
    return this->name;
}

bool    Form::getIsSigned() const {
    return this->isSigned;
}

int Form::getExecGrade() const {
    return this->execGrade;
}

int Form::getSignGrade() const {
    return this->signGrade;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade : Too high !!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade : Too low !!";
}

std::ostream&    operator<<(std::ostream& os, const Form& obj){
    std::string str =  obj.getIsSigned() ? "signed" : "not signed";
    return os << obj.getName() << " [" << str 
              << "], execution grade : " << obj.getExecGrade() << " and sign grade : "
              << obj.getSignGrade();
}

void        Form::beSigned(Bureaucrat& obj){
    if (obj.getGrade() > this->signGrade){
        std::cout << obj.getName() << " couldn't sign " << this->name << " because the grade is too low !\n"; 
        throw Form::GradeTooLowException();
    }
    std::cout << obj.getName() << " signed " << this->name << std::endl; 
    isSigned = true;
}
