#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), target("Default target"){
    std::cout << "Default ShrubberyCreationForm Constructor called !" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Default ShrubberyCreationForm Destructor called !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &assign) :  AForm(assign), target(assign.target){
    std::cout << "ShrubberyCreationForm Copy Constructor called !" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign){
    if (this != &assign){
        this->target = assign.target;
        AForm::operator=(assign);
    }
    return *this;
}
const char* ShrubberyCreationForm::OpenFileException::what() const throw() {
    return "Cannot open file !!";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 137, 145), target(target){
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    if (!this->getIsSigned())
        throw AForm::GradeNotSignedException();
    std::ofstream file;
    std::string fileName = target + "_shrubbery";
    file.open(fileName.c_str());
    if (!file.is_open())
        throw OpenFileException();
    file <<
        "       _-_        \n"
        "    /~~   ~~\\    \n"
        " /~~         ~~\\ \n"
        "{               } \n"
        " \\  _-     -_  / \n"
        "   ~  \\\\ //  ~   \n"
        "_- -   | | _- _  \n"
        "  _ -  | |   -_  \n"
        "      // \\\\      \n"
        "     //   \\\\     \n"
        "    //     \\\\    \n";
    file.close();
}
