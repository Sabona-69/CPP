#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &assign);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &assign);
        PresidentialPardonForm(const AForm &obj);
};

#endif
