#include "PmergeMe.hpp"

int main(int argc, char **argv){

	try
	{
		PmergeMe pmergeMe;
		if (argc < 2) throw std::runtime_error("Error: Not enough arguments");
		pmergeMe.fillContainers(argv);
		
		
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error :" << e.what() << '\n';
		return 1;
	}
	
	return 0;
}