#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat test1("alo", 10);
        test1.setGrade(0);
    }

    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << "Exception called : " <<  e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << "Exception called : " <<  e.what() << std::endl;
    }
    return 0;
}
