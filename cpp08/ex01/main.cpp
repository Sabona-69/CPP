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
	
	
		// 1000 number test
		Span sp2(10);
		sp2.addNumber(10, RANDOM);
		for (size_t i = 0; i < sp2.getMax(); ++i){
			std::cout << "num [" << i <<  "] : " << sp2.getVecNum()[i] << std::endl;
		}
		
		std::vector<int> copy = sp2.getVecNum();
		std::cout << std::string(100, '=') << std::endl;
		std::sort(copy.begin(), copy.end());
		for (size_t i = 0; i < copy.size(); ++i) {
			std::cout << "num [" << i <<  "] : " << copy[i] << std::endl;
		}
			

	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught : " << e.what() << '\n';
	}
	




}