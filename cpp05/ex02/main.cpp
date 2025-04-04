#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    Bureaucrat president("Zaphod", 1);
    Bureaucrat clerk("Hermes", 46);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur");

    // Sign the forms first!
    president.signForm(shrub);
    president.signForm(robot);
    president.signForm(pardon);

    // Execute the signed forms
    president.executeForm(shrub);  // Success
    president.executeForm(robot);  // 50% success
    president.executeForm(pardon); // Success

    // Clerk tries to execute robotomy (signed but grade too low)
    clerk.executeForm(robot);

    return 0;
}