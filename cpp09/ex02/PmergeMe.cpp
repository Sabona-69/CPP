#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
    std::cout << "Default PmergeMe Constructor called !" << std::endl;
}

PmergeMe::~PmergeMe(){
    std::cout << "Default PmergeMe Destructor called !" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &assign){
    std::cout << "PmergeMe Copy Constructor called !" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &assign){
    if (this != &assign){
        // Assignment logic here
    }
    return *this;
}

bool isAllDegit(char *str){
	for (size_t i = 0; str[i] != '\0'; ++i) {
		if (!isdigit(str[i]))
			return false;	
	}
	return true;	
}

void PmergeMe::fillContainers(char **argv) {
	for (int i = 1; argv[i] != NULL; i++) {
		if (isAllDegit(argv[i]) == false)
			throw std::runtime_error("Invalid input");
		long num = atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN) {
			throw std::runtime_error("Invalid input");
		}
		_vector.push_back(num);
		_deque.push_back(num);
	}

}
