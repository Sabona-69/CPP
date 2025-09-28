#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char **argv){

	try
	{
		if (argc < 2) throw std::runtime_error("Error: Not enough arguments");
		
		PmergeMe pmergeMe;
	
		pmergeMe.fillContainers(argv);
		pmergeMe.printContainer("Before: ");

		clock_t start = clock();
		pmergeMe.sortDeque();
		clock_t end = clock();
		double deqTime = double(end - start) / CLOCKS_PER_SEC * 1000000;

		start = clock();
		pmergeMe.sortVector();
		end = clock();
		double vecTime = double(end - start) / CLOCKS_PER_SEC * 1000000;

		pmergeMe.printContainer("After: ");
		std::cout << "Time to process a range of " << pmergeMe.getDeque().size() << " elements with std::deque : " << deqTime << " us" << std::endl;
		std::cout << "Time to process a range of " << pmergeMe.getVector().size() << " elements with std::vector : " << vecTime << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error :" << e.what() << '\n';
		return 1;
	}
	
	return 0;
}