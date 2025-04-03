#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(){
    std::cout << "Default RobotomyRequestForm Constructor called !" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Default RobotomyRequestForm Destructor called !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const AForm &obj){
    std::cout << std::string('#', 30) << std::endl; 
    if (obj.getSignGrade() == 72 && obj.getExecGrade() == 45)
        std::cout << obj.getName() <<" has been robotomized successfully 50% of the time\n";
    else
        std::cout << " The robotomy failed !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &assign) : AForm(assign){
    std::cout << "RobotomyRequestForm Copy Constructor called !" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &assign){
    if (this != &assign){
        AForm::operator=(assign);
    }
    return *this;
}
