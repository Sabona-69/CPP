#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "=== Testing MutantStack with int ===" << std::endl;
    
    // Test forward iterators
    std::cout << "\n--- Testing Forward Iterators ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Stack size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Elements using forward iterator: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // Test reverse iterators
    std::cout << "\n--- Testing Reverse Iterators ---" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    std::cout << "Elements using reverse iterator: ";
    while (rit != rite)
    {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;

    // Test const iterators
    std::cout << "\n--- Testing Const Iterators ---" << std::endl;
    const MutantStack<int> const_mstack = mstack;
    MutantStack<int>::const_iterator cit = const_mstack.begin();
    MutantStack<int>::const_iterator cite = const_mstack.end();
    std::cout << "Elements using const iterator: ";
    while (cit != cite)
    {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;

    // Test const reverse iterators
    std::cout << "\n--- Testing Const Reverse Iterators ---" << std::endl;
    MutantStack<int>::const_reverse_iterator crit = const_mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = const_mstack.rend();
    std::cout << "Elements using const reverse iterator: ";
    while (crit != crite)
    {
        std::cout << *crit << " ";
        ++crit;
    }
    std::cout << std::endl;

    // Test with a larger dataset
    std::cout << "\n--- Testing with larger dataset ---" << std::endl;
    MutantStack<int> test;
    for (int i = 1; i <= 10; ++i) {
        test.push(i * 10);
    }

    std::cout << "Forward iteration: ";
    for (MutantStack<int>::iterator it = test.begin(); it != test.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse iteration: ";
    for (MutantStack<int>::reverse_iterator rit = test.rbegin(); rit != test.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Test with different data type (char)
    std::cout << "\n=== Testing MutantStack with char ===" << std::endl;
    MutantStack<char> charStack;
    charStack.push('A');
    charStack.push('B');
    charStack.push('C');
    charStack.push('D');

    std::cout << "Char stack forward: ";
    for (MutantStack<char>::iterator it = charStack.begin(); it != charStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Char stack reverse: ";
    for (MutantStack<char>::reverse_iterator rit = charStack.rbegin(); rit != charStack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Test std::stack compatibility
    std::cout << "\n--- Testing std::stack compatibility ---" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "Size of copied stack: " << s.size() << std::endl;

	MutantStack<int, std::list<int> > lsss;
	std::list<int> ls;

	
	std::stack<int ,std::list<int> > __test(ls);
	

    return 0;
}