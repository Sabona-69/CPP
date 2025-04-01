#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string     name;
        bool                  isSigned;
        const int             execGrade;
        const int             signGrade;
    public:
        Form();
        ~Form();
        Form(const Form &assign);
        Form& operator=(const Form &assign);
        std::string getName() const;
        bool        getIsSigned() const;
        int         getExecGrade() const;
        int         getSignGrade() const;
        void        beSigned(Bureaucrat& obj);
        class GradeTooHighException : public std::exception {
            const char* what() throw();
        };
        class GradeTooLowException : public std::exception {
            const char* what() throw();
        };
};

std::ostream&   operator<<(std::ostream& os, const Form& obj);

#endif
