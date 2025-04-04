#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(), target("Default target"){
    std::cout << "Default RobotomyRequestForm Constructor called !" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Default RobotomyRequestForm Destructor called !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &assign) :  AForm(assign), target(assign.target){
    std::cout << "RobotomyRequestForm Copy Constructor called !" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &assign){
    if (this != &assign){
        this->target = assign.target;
        AForm::operator=(assign);
    }
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 45, 72), target(target){
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    std::cout << std::string(15, '#') << " NOISE " << std::string(15, '#') << std::endl; 
    if (executor.getGrade() > this->getExecGrade() || !this->getIsSigned()){
        std::cout << "The robotomy failed !" << std::endl;
        !this->getIsSigned() ? throw AForm::GradeNotSignedException() : throw AForm::GradeTooLowException();
    }
    std::cout << target <<" has been robotomized successfully 50% of the time\n";
}