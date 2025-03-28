#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
    private:
        const std::string name;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &assign);
        Bureaucrat& operator=(const Bureaucrat &assign);
        class GradeTooHighException : public std::exception
        {
            public:
            virtual void    what();
            
        };
        class GradeTooLowException : public std::exception
        {
            public:
            // void    what();

        };
};

#endif
