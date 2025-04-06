#include <iostream>
#include "Base.hpp"

int main() {

    Base* ptr = generate();       // Create a new A/B/C instance randomly
    identify(ptr);                // Identify using pointer
    identify(*ptr);               // Identify using reference
    delete ptr;                   // Free memory
    std::cout << "----------------------" << std::endl;
    return 0;
}
