#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	// main tests
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(mstack);
	std::cout << "size of s "<< s.size();
   
    std::cout << std::string(50, '=') <<  std::endl;

    // test reverse iterators
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    std::cout << "Elements using reverse iterator: ";
    while (rit != rite)
    {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl  << std::string(50, '=') <<  std::endl;


    // test const iterators
    const MutantStack<int> const_mstack = mstack;
    MutantStack<int>::const_iterator cit = const_mstack.begin();
    MutantStack<int>::const_iterator cite = const_mstack.end();
    std::cout << "Elements using const iterator: ";
    while (cit != cite)
    {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout <<  std::endl << std::string(50, '=') <<  std::endl;


    // test const reverse iterators
    MutantStack<int>::const_reverse_iterator crit = const_mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = const_mstack.rend();
    std::cout << "Elements using const reverse iterator: ";
    while (crit != crite)
    {
        std::cout << *crit << " ";
        ++crit;
    }
    std::cout << std::endl <<std::string(50, '=') <<  std::endl;
	
	MutantStack<int> cpycons(mstack);
    std::cout << "Size of copied stack: " << cpycons.size() << std::endl;


    return 0;
}