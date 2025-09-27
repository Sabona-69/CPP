#include "PmergeMe.hpp"
#include <sys/time.h>

int main(int argc, char **argv){

	try
	{
		if (argc < 2) throw std::runtime_error("Error: Not enough arguments");
		
		// Create container copies manually to test the algorithm
		std::vector<int> vector_container;
		std::deque<int> deque_container;
		
		for (int i = 1; argv[i] != NULL; i++) {
			if (isAllDegit(argv[i]) == false)
				throw std::runtime_error("Invalid input");
			long num = atol(argv[i]);
			if (num > INT_MAX || num < INT_MIN) {
				throw std::runtime_error("Invalid input");
			}
			vector_container.push_back(num);
			deque_container.push_back(num);
		}

		// Print before sorting
		std::cout << "Before: ";
		for(size_t i = 0; i < vector_container.size(); i++) {
			std::cout << vector_container[i] << " ";
		}
		std::cout << std::endl;
		
		// Time the Ford-Johnson sort for vector
		struct timeval start, end;
		gettimeofday(&start, NULL);
		PmergeMe pmergeMe_vector;
		pmergeMe_vector.sort(vector_container);
		gettimeofday(&end, NULL);
		long vector_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
		
		// Time the Ford-Johnson sort for deque
		gettimeofday(&start, NULL);
		PmergeMe pmergeMe_deque;
		pmergeMe_deque.sort(deque_container);
		gettimeofday(&end, NULL);
		long deque_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
		
		// Print after sorting
		std::cout << "After: ";
		for(size_t i = 0; i < vector_container.size(); i++) {
			std::cout << vector_container[i] << " ";
		}
		std::cout << std::endl;
		
		std::cout << "Time to process a range of " << vector_container.size() << " elements with std::vector : " << vector_time << " us" << std::endl;
		std::cout << "Time to process a range of " << deque_container.size() << " elements with std::deque : " << deque_time << " us" << std::endl;

		
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error :" << e.what() << '\n';
		return 1;
	}
	
	return 0;
}