#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &assign);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &assign);
        ShrubberyCreationForm(const AForm &obj);
        class OpenFileException : std::exception {
            const char* what() const throw();
        };
};

#endif
