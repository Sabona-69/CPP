#include <iostream>
#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main() {
    Intern intern;
    AForm* forms[4];

    // Valid forms
    forms[0] = intern.makeForm("shrubbery creation", "Garden");
    forms[1] = intern.makeForm("robotomy request", "Bender");
    forms[2] = intern.makeForm("presidential pardon", "Arthur");

    // Invalid form
    try { forms[3] = intern.makeForm("invalid form", "Target"); }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    // Cleanup
    for (int i = 0; i < 3; i++) delete forms[i];
    return 0;
}