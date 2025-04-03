#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;
class Bureaucrat {
    private:
        const std::string name;
        int               grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &assign);
        Bureaucrat& operator=(const Bureaucrat &assign);
        Bureaucrat(std::string name, int grade);
        std::string getName() const;
        int         getGrade() const;
        void        setGrade(int grade);
        void        incrementGrade();
        void        decrementGrade();
        void        signForm(Form& obj);

        class GradeTooHighException : public std::exception
        {
            public:
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
            virtual const char* what() const throw();
            
        };
    };
    std::ostream&    operator<<(std::ostream& os, const Bureaucrat& obj);
    
#endif
