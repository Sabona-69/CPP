#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string     name;
        bool                  isSigned;
        const int             execGrade;
        const int             signGrade;
    public:
        AForm();
        ~AForm();
        AForm(const AForm &assign);
        AForm& operator=(const AForm &assign);
        std::string getName() const;
        bool        getIsSigned() const;
        int         getExecGrade() const;
        int         getSignGrade() const;
        void        beSigned(Bureaucrat& obj);
        class GradeTooHighException : public std::exception {
            const char* what()  const throw();
        };
        class GradeTooLowException : public std::exception {
            const char* what()  const throw();
        };
        virtual void execute(Bureaucrat const & executor) = 0;
};

std::ostream&   operator<<(std::ostream& os, const AForm& obj);

#endif
