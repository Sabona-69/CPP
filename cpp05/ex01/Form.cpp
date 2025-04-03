#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), execGrade(0), signGrade(0) {
    std::cout << "Default Form Constructor called !" << std::endl;
}

Form::~Form(){
    std::cout << "Default Form Destructor called !" << std::endl;
}

Form::Form(const Form &assign) :
    name(assign.name), isSigned(assign.isSigned), execGrade(assign.execGrade), signGrade(assign.signGrade){
    std::cout << "Form Copy Constructor called !" << std::endl;
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
    return "Grade : Too Low !!";
}

std::ostream&    operator<<(std::ostream& os, const Form& obj){
    return os << obj.getName() << ", the sign is : " << obj.getIsSigned() 
              << " , execution grade : " << obj.getExecGrade() << " and sign grade : "
              << obj.getSignGrade() << std::endl;
}

void        Form::beSigned(Bureaucrat& obj){
    if (obj.getGrade() < 1 || obj.getGrade() > 150){
        std::cout << obj.getName() << " couldn't sign " << this->name << "because " ; 
        obj.getGrade() < 1 ? throw Form::GradeTooHighException() : throw Form::GradeTooLowException();
    }
    std::cout << obj.getName() << " signed " << this->name << std::endl; 
    isSigned = true;
}
