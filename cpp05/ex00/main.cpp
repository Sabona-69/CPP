#include "Bureaucrat.hpp"


int main() {
    // Valid grades
    Bureaucrat b1("Alice", 1);
    Bureaucrat b2("Bob", 150);
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    // Invalid grades
    try { Bureaucrat b3("Invalid", 0); }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }

    try { Bureaucrat b4("Invalid", 151); }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }

    // Increment/Decrement
    try {
        b1.decrementGrade();  // 1 → 2
        b2.incrementGrade();  // 150 → 149
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
    } catch (std::exception& e) { std::cerr << e.what() << std::endl; }

    return 0;
}