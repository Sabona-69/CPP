#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"


class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &assign);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &assign);
        RobotomyRequestForm(const AForm& obj);
};

#endif
