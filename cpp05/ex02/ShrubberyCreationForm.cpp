#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
    std::cout << "Default ShrubberyCreationForm Constructor called !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm (const AForm &obj) {
    if (obj.getSignGrade() == 145 && obj.getExecGrade() == 137)
    {
        std::ofstream file;
        std::string fileName = obj.getName() + "_shrubbery";
        file.open(fileName);
        if (!file.is_open())
            throw OpenFileException();
        file << "hello";          
    }
}

const char* ShrubberyCreationForm::OpenFileException:: what() const throw(){
    return "Cannot open file !";
} 

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Default ShrubberyCreationForm Destructor called !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &assign) : AForm(assign) {
    std::cout << "ShrubberyCreationForm Copy Constructor called !" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign){
    if (this != &assign){
        AForm::operator=(assign);
    }
    return *this;
}
