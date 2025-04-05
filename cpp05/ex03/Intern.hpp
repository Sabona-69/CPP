#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
    public:
        Intern();
        ~Intern();
        Intern(const Intern &assign);
        Intern& operator=(const Intern &assign);
        AForm    *makeForm(std::string form, std::string target);
        AForm    *presidential(std::string target);
        AForm    *robotomy(std::string target);
        AForm    *shrubbery(std::string target);
    };

#endif
