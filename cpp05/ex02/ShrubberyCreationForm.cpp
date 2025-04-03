#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : target("Default target") {
    std::cout << "Default ShrubberyCreationForm Constructor called !" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Default ShrubberyCreationForm Destructor called !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &assign) : target(assign.target){
    std::cout << "ShrubberyCreationForm Copy Constructor called !" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign){
    if (this != &assign){
        this->target = assign.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) {
    if (this->getSignGrade() == 145 && this->getExecGrade() == 137)
    {
        std::ofstream file;
        std::string fileName = target + "_shrubbery";
        file.open(fileName);
        if (!file.is_open())
            throw OpenFileException();
        file << "hello";          
    }
}
