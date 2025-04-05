#include "Intern.hpp"

Intern::Intern(){
    std::cout << "Default Intern Constructor called !" << std::endl;
}

Intern::~Intern(){
    std::cout << "Default Intern Destructor called !" << std::endl;
}

Intern::Intern(const Intern &assign) {
    (void)assign;
    std::cout << "Intern Copy Constructor called !" << std::endl;
}

Intern& Intern::operator=(const Intern &assign){
    (void)assign;
    if (this != &assign){
        // Assignment logic here
    }
    return *this;
}

AForm*    Intern::presidential(std::string target){
    return new PresidentialPardonForm(target);
}

AForm*    Intern::robotomy(std::string target){
    return new RobotomyRequestForm(target);
}

AForm*    Intern::shrubbery(std::string target){
    return new ShrubberyCreationForm(target);
}


AForm* Intern::makeForm(std::string form, std::string target){
    std::string forms[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };
    AForm* (Intern::*func[])(std::string) = {&Intern::presidential, &Intern::robotomy, &Intern::shrubbery};    
    for (int i = 0; i < 3; i++) {
        if (forms[i] == form){
            std::cout << "Intern Creates : " << form << std::endl;
            return (this->*func[i])(target);
        }
    }
    std::cout << form <<" : Invalid Form !!" << std::endl;
    return NULL;
}
