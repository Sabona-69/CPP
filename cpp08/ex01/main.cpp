#include "Span.hpp"
#include <climits>
#include <iostream>

int main()
{
    std::cout << "=== TEST 1: Basic functionality with INT_MAX and INT_MIN ===" << std::endl;
    try
    {
        Span sp = Span(2);
        sp.addNumber(INT_MAX);
        sp.addNumber(INT_MIN);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Expected: 4294967295
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Expected: 4294967295
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    std::cout << "\n=== TEST 2: Adding more numbers than capacity ===" << std::endl;
    try
    {
        Span sp = Span(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);  // Should throw exception
        std::cout << "This shouldn't print" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';  // Expected: There is no space left !
    }

    std::cout << "\n=== TEST 3: Calculating span with only one number ===" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl;  // Should throw exception
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';  // Expected: Not enough elements
    }

    std::cout << "\n=== TEST 4: Calculating span with no numbers ===" << std::endl;
    try
    {
        Span sp = Span(5);
        std::cout << sp.longestSpan() << std::endl;  // Should throw exception
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';  // Expected: Not enough elements
    }

    std::cout << "\n=== TEST 5: Attempting to add duplicate numbers ===" << std::endl;
    try
    {
        Span sp = Span(3);
        sp.addNumber(5);
        sp.addNumber(5);  // Should throw exception
        std::cout << "This shouldn't print" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';  // Expected: The number you tried to add already exist !
    }

    std::cout << "\n=== TEST 6: Sequential numbers ===" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
        sp.addNumber(5);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Expected: 1
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Expected: 4
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    std::cout << "\n=== TEST 7: Random numbers (no duplicates) ===" << std::endl;
    try
    {
        Span sp = Span(6);
        sp.addNumber(3);
        sp.addNumber(1);
        sp.addNumber(4);
        sp.addNumber(2);  // Changed from duplicate 1
        sp.addNumber(5);
        sp.addNumber(9);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Expected: 1 (2-1 or 3-2 or 4-3 or 5-4)
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Expected: 8 (9-1)
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    std::cout << "\n=== TEST 8: Negative numbers ===" << std::endl;
    try
    {
        Span sp = Span(4);
        sp.addNumber(-10);
        sp.addNumber(-5);
        sp.addNumber(-1);
        sp.addNumber(-20);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Expected: 4 (|-1 - (-5)| = 4)
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Expected: 19 (|-1 - (-20)| = 19)
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    std::cout << "\n=== TEST 9: Mixed positive and negative ===" << std::endl;
    try
    {
        Span sp = Span(4);
        sp.addNumber(-100);
        sp.addNumber(0);
        sp.addNumber(50);
        sp.addNumber(-25);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Expected: 25 (|-25 - 0| = 25)
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Expected: 150 (|50 - (-100)| = 150)
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    std::cout << "\n=== TEST 10: Large span with zero ===" << std::endl;
    try
    {
        Span sp = Span(3);
        sp.addNumber(INT_MAX);
        sp.addNumber(0);
        sp.addNumber(INT_MIN);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Expected: 2147483647
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Expected: 4294967295
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    std::cout << "\n=== TEST 11: Empty span creation ===" << std::endl;
    try
    {
        Span sp = Span(0);
        std::cout << "Created empty span successfully" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    std::cout << "\n=== TEST 12: Single element span ===" << std::endl;
    try
    {
        Span sp = Span(1);
        sp.addNumber(42);
        std::cout << "Added number to single-element span" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    std::cout << "\n=== TEST 13: Attempting to calculate span on single element ===" << std::endl;
    try
    {
        Span sp = Span(1);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl;  // Should throw exception
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';  // Expected: Not enough elements
    }

    std::cout << "\n=== TEST 14: Maximum capacity test ===" << std::endl;
    try
    {
        Span sp = Span(10000);
        for (int i = 0; i < 10000; i++) {
            sp.addNumber(i * 2);
        }
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Expected: 2
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Expected: 19998
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    std::cout << "\n=== TEST 15: Adding numbers after span calculation ===" << std::endl;
    try
    {
        Span sp = Span(3);
        sp.addNumber(1);
        sp.addNumber(3);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Expected: 2
        sp.addNumber(2);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Expected: 1
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Expected: 2
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    std::cout << "\n=== TEST 16: Testing with size 1 span ===" << std::endl;
    try
    {
        Span sp = Span(1);
        // Just test that it can be created and used without crashing
        std::cout << "Span of size 1 created successfully" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}