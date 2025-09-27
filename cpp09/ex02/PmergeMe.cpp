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

template <typename Container>
void printContainer(const Container &container, const std::string& msg) {
	typename Container::const_iterator it = container.begin();
	typename Container::const_iterator ite = container.end();
	std::cout << msg;
	while (it != ite) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
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


