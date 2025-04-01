#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat test1("alo", 10);
        std::cout << test1 << std::endl;
        test1.setGrade(160);
        // test1.setGrade(0);
    }
    
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << "Exception called : " <<  e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << "Exception called : " <<  e.what() << std::endl;
    }
    return 0;
}
