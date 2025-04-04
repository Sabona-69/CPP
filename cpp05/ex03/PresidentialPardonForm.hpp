#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    private:
        std::string     target;
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &assign);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &assign);
        PresidentialPardonForm(const std::string &target);
        void    execute(Bureaucrat const & executor) const;
};

#endif
