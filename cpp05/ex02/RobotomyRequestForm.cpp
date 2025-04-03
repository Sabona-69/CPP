#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : target("Default target") {
    std::cout << "Default RobotomyRequestForm Constructor called !" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Default RobotomyRequestForm Destructor called !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &assign) : target(assign.target){
    std::cout << "RobotomyRequestForm Copy Constructor called !" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &assign){
    if (this != &assign){
        this->target = assign.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) {
    std::cout << std::string('#', 30) << std::endl; 
    if (this->getSignGrade() == 72 && this->getExecGrade() == 45)
    std::cout << target <<" has been robotomized successfully 50% of the time\n";
    else
    std::cout << " The robotomy failed !" << std::endl;
}