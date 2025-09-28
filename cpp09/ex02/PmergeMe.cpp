#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::~PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe &assign){
    this->_vector = assign._vector;
    this->_deque = assign._deque;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &assign){
    if (this != &assign){
        this->_vector = assign._vector;
        this->_deque = assign._deque;
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

std::vector<int> PmergeMe::getVector() const {
	return _vector;
}

std::deque<int> PmergeMe::getDeque() const {
	return _deque;
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

void PmergeMe::printContainer(const std::string& msg) {
	std::cout << msg;
	for (size_t i = 0; i < _vector.size(); i++) {
		std::cout << _vector[i];
		if (i != _vector.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::sortVector() {
	std::vector<std::pair<int, int>> pairs;

	if (_vector.size() <= 1) return ;

	for (size_t i = 0; i < _vector.size(); i += 2) {
		if (i + 1 < _vector.size()) {
			if (_vector[i] < _vector[i + 1]) {
						
				
			} else {
				
			}
		} else {
			
		}
	}
	// for (size_t i = 0; i < large.size(); i++) 
	// 	std::cout << large[i] << " ";
	// for (size_t i = 0; i < small.size(); i++)
	// 	std::cout << small[i] << " ";


}

void	PmergeMe::sortDeque() {

}
