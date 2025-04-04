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

AForm* Intern::makeForm(std::string form, std::string target){
    
    AForm   *ret;
    int     input;

    std::string forms[3] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    for (input = 0; input < 3; input++){
        if (forms[input] == form)
            break ;
    }
    switch (input)
    {
        case 0:
            ret = new RobotomyRequestForm(target); 
            break;
        case 1:
            ret = new PresidentialPardonForm(target); 
            break;
        case 2:
            ret = new ShrubberyCreationForm(target); 
            break;
        default:
            std::cout << "Invalid Form !!" << std::endl;
            ret = NULL;
            break;
        }
        return ret;
}