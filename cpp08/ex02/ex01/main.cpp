#include "Span.hpp"

#include <climits>
#include <iostream>

int main()
{
	try
	{
		// main subject 
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	
		std::cout << std::string(100, '=') << std::endl;
	
		// 1000 number test
		Span sp2(1000);
		std::vector<int> vec;
		for (size_t i = 0; i < sp2.getMax(); ++i){
			vec.push_back(i + 1);
		}
		sp2.addNumber(vec.begin(), vec.end());		

		// for (size_t i = 0; i < sp2.getMax(); ++i) {
		// 	std::cout << "sp2 [" << i <<  "] : " << sp2.getVecNum()[i] << std::endl;
		// }
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
		std::cout << std::string(100, '=') << std::endl;
		

	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught : " << e.what() << '\n';
	}

}