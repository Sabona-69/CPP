#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"


class RobotomyRequestForm : public AForm {
    private:
        std::string     target;
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &assign);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &assign);
        RobotomyRequestForm(const std::string &target);
        void    execute(Bureaucrat const & executor);
};

#endif
