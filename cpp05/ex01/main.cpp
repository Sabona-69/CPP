#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat ceo("Elon", 1);
    Bureaucrat intern("Bob", 150);

    Form formA("Tax Form", 1, 1);
    Form formB("Permit", 149, 149);

    // CEO signs high-grade form
    ceo.signForm(formA);
    std::cout << formA << std::endl;

    // Intern tries to sign
    try {
        intern.signForm(formB);  // Fails
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught : " << e.what() << std::endl;  
    }

    return 0;
}