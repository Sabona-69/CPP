#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default") , grade(1){
    std::cout << "Default Bureaucrat Constructor called !" << std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Default Bureaucrat Destructor called !" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &assign) : name(assign.name),  grade(assign.grade) {
    std::cout << "Bureaucrat Copy Constructor called !" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name){
    if (grade < 1 || grade > 150)
        grade < 1 ? throw GradeTooHighException() : throw GradeTooLowException();
    this->grade = grade;
}
    
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade : Too high !!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade : Too low !!";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &assign){
    if (this != &assign){
        this->grade = assign.grade;
    }
    return *this;
}

std::string Bureaucrat::getName() const{
    return this->name;
}

int Bureaucrat::getGrade() const{
    return this->grade;
}

void    Bureaucrat::setGrade(int grade){
    if (grade < 1 || grade > 150)
        grade < 1 ? throw GradeTooHighException() : throw GradeTooLowException();
    this->grade = grade; 
}

void    Bureaucrat::incrementGrade(){
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void    Bureaucrat::decrementGrade(){
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

std::ostream&    operator<<(std::ostream& os, const Bureaucrat& obj){
    return os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
}

void    Bureaucrat::signForm(AForm& obj){
    obj.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const & form){
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e){
        std::cout << this->getName() << " couldn't execute " << form.getName() << std::endl;
        std::cout << "Exception Caught : " << e.what() << std::endl; 
    }
}