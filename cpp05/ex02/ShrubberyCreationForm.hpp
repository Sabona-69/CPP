#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm {
    private:
        std::string     target;
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &assign);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &assign);
        ShrubberyCreationForm(const std::string &target);
        class OpenFileException : std::exception {
            const char* what() const throw();
        };
        void    execute(Bureaucrat const & executor);
};

#endif
