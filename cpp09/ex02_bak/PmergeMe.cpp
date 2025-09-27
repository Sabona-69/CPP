#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
    //std::cout << "Default PmergeMe Constructor called !" << std::endl;
}

PmergeMe::~PmergeMe(){
    //std::cout << "Default PmergeMe Destructor called !" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &assign){
    //std::cout << "PmergeMe Copy Constructor called !" << std::endl;
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

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t size) {
    std::vector<size_t> sequence;
    
    // For the Ford-Johnson algorithm, we need to handle all elements
    // Even if size is 0 or 1, we should have a proper sequence
    
    if (size == 0) return sequence;
    
    // For size 1, just return index 0 (first element)
    if (size == 1) {
        sequence.push_back(0);
        return sequence;
    }

    // Generate the sequence of indices in the order they should be inserted
    // according to the Ford-Johnson algorithm using Jacobsthal numbers
    
    // The insertion sequence follows this pattern based on Jacobsthal numbers:
    // J(n) = (2^n - (-1)^n)/3
    // J(1)=1, J(2)=1, J(3)=3, J(4)=5, J(5)=11, J(6)=21, etc.

    // Calculate Jacobsthal numbers up to size
    std::vector<size_t> jacobsthal_nums;
    jacobsthal_nums.push_back(0); // J(0) = 0
    jacobsthal_nums.push_back(1); // J(1) = 1
    jacobsthal_nums.push_back(1); // J(2) = 1
    
    size_t n = 3;
    while (true) {
        size_t next_jacobsthal = (jacobsthal_nums[n-1] + 2 * jacobsthal_nums[n-2]);
        if (next_jacobsthal > size) break;
        jacobsthal_nums.push_back(next_jacobsthal);
        n++;
    }

    // Build insertion sequence: insert elements in order determined by Jacobsthal numbers
    // For each Jacobsthal number J(n), insert in decreasing order
    for (size_t i = 1; i < jacobsthal_nums.size(); i++) {
        size_t start = (i == 1) ? 1 : jacobsthal_nums[i-1] + 1;  // Start after previous range
        size_t end = jacobsthal_nums[i];                        // End at current Jacobsthal number
        
        if (start > size) break;
        if (end > size) end = size;
        
        // Insert in decreasing order within the range
        for (int idx = end; idx >= (int)start; idx--) {
            if (idx == 0) break;  // Prevent underflow
            sequence.push_back(idx - 1);  // Convert to 0-based indexing
        }
    }
    
    // Make sure we have all indices covered, add any missing ones
    // This is a fallback to ensure all elements get inserted
    for (size_t i = 0; i < size; i++) {
        bool found = false;
        for (std::vector<size_t>::const_iterator it = sequence.begin(); it != sequence.end(); ++it) {
            if (*it == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            sequence.push_back(i);
        }
    }
    
    return sequence;
}

std::vector<int> PmergeMe::getVector() const {
	return _vector;
}

std::deque<int> PmergeMe::getDeque() const {
	return _deque;
}

template <typename Container>
void printContainer(const Container &container) {
	typename Container::const_iterator it = container.begin();
	typename Container::const_iterator ite = container.end();
	std::cout << "Before: ";
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


