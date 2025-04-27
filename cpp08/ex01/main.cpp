#include "Span.hpp"

int main()
{
    std::vector<int> a(3);
    std::vector<int> b = {1, 2, 3};


    a = b;

    for (size_t i = 0; i < 3; i++)
    {
        b[0] = 1000;
        std::cout << "address of a "<< &a << std::endl;
        std::cout << "address of b "<< &b << std::endl;
        std::cout << "b = " << b[i] << std::endl;
        std::cout << "a = " << a[i] << std::endl;
    }
    
    // b.pu

    // Span sp = Span(5);
    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;
    return 0;
}