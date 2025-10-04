#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){ }

PmergeMe::~PmergeMe(){ }

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

std::vector<int> PmergeMe::getVector() const { return _vector;}

std::deque<int> PmergeMe::getDeque() const { return _deque; }

bool isAllDegit(char *str){
	for (size_t i = 0; str[i] != '\0'; ++i) {
		if (!isdigit(str[i]))
			return false;	
	}
	return true;	
}

void	PmergeMe::fillContainers(int type) {
	if (type == VECTOR) {
		for (size_t i = 0; i < inputs.size(); ++i) {
			_vector.push_back(inputs[i]);
		}
	} else {
		for (size_t i = 0; i < inputs.size(); ++i) {
			_deque.push_back(inputs[i]);
		}
	}
}

void	PmergeMe::parseInput(char **av) {
	for (int i = 1; av[i] != NULL; i++) {
		if (isAllDegit(av[i]) == false)
			throw std::runtime_error("Invalid input");
		long num = atol(av[i]);
		if (num > INT_MAX || num < INT_MIN) {
			throw std::runtime_error("Invalid input");
		}
		inputs.push_back(num);
	}
}

void PmergeMe::printContainer(const std::string& msg){
	if (msg == "After: ")
		inputs = _vector;
	std::cout << msg;
	for (size_t i = 0; i < inputs.size(); i++) {
		std::cout << inputs[i];
		if (i != inputs.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}


// Binary insertion with search limited to [0, maxPos]
void PmergeMe::insertBinaryLimited(std::deque<int>& vec, int value, size_t maxPos) {
	size_t left = 0;
	size_t right = std::min(maxPos + 1, vec.size());
		
	while (left < right) {
		size_t mid = left + (right - left) / 2;
		if (vec[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	vec.insert(vec.begin() + left, value);
}

// Generate Jacobsthal numbers: t_k = t_{k-1} + 2*t_{k-2}, t_0=0, t_1=1
std::deque<size_t> PmergeMe::generateJacobsthalDeque(size_t limit) {
	std::deque<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
		
	while (true) {
		size_t next = jacobsthal[jacobsthal.size() - 1] + 
					 2 * jacobsthal[jacobsthal.size() - 2];
		if (next > limit)
			break;
		jacobsthal.push_back(next);
	}
		
	return jacobsthal;
}

// Generate insertion order: t_{k+1}-1, t_{k+1}-2, ..., t_k (descending within each group)
std::deque<size_t> PmergeMe::getInsertionOrderDeque(size_t n) {
	if (n == 0) return std::deque<size_t>();

	std::deque<size_t> jacobsthal = generateJacobsthalDeque(n + 1);
	std::deque<size_t> order;
		
	// Start from J_3 = 3 (index 3 in jacobsthal array)
	for (size_t i = 2; i < jacobsthal.size(); i++) {
		size_t current = jacobsthal[i];
		size_t previous = (i > 0) ? jacobsthal[i - 1] : 0;
		
		// Insert indices from current down to previous+1
		for (size_t j = std::min(current, n); j > previous && j > 0; j--) {
			order.push_back(j);
		}
		
		if (current >= n)
			break;
	}
		
	// Add any remaining indices not covered by Jacobsthal sequence
	std::deque<bool> used(n + 1, false);
	for (size_t i = 0; i < order.size(); i++) {
    	if (order[i] <= n)
        	used[order[i]] = true;
	}
	for (size_t i = 1; i <= n; i++) {
		if (!used[i]) {
			order.push_back(i);
		}
	}
		
	return order;
}


// Binary insertion with search limited to [0, maxPos]
void PmergeMe::insertBinaryLimited(std::vector<int>& vec, int value, size_t maxPos) {
	size_t left = 0;
	size_t right = std::min(maxPos + 1, vec.size());
		
	while (left < right) {
		size_t mid = left + (right - left) / 2;
		if (vec[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	vec.insert(vec.begin() + left, value);
}

// Generate Jacobsthal numbers: t_k = t_{k-1} + 2*t_{k-2}, t_0=0, t_1=1
std::vector<size_t> PmergeMe::generateJacobsthal(size_t limit) {
	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
		
	while (true) {
		size_t next = jacobsthal[jacobsthal.size() - 1] + 
					 2 * jacobsthal[jacobsthal.size() - 2];
		if (next > limit)
			break;
		jacobsthal.push_back(next);	
	}
		
	return jacobsthal;
}

// Generate insertion order: t_{k+1}-1, t_{k+1}-2, ..., t_k (descending within each group)
std::vector<size_t> PmergeMe::getInsertionOrder(size_t n) {
	if (n == 0) return std::vector<size_t>();

	std::vector<size_t> jacobsthal = generateJacobsthal(n + 1);
	std::vector<size_t> order;
		
	// Start from J_3 = 3 (index 3 in jacobsthal array)
	for (size_t i = 2; i < jacobsthal.size(); i++) {
		size_t current = jacobsthal[i];
		size_t previous = (i > 0) ? jacobsthal[i - 1] : 0;
		
		// Insert indices from current down to previous+1
		for (size_t j = std::min(current, n); j > previous && j > 0; j--) {
			order.push_back(j);
		}
		
		if (current >= n)
			break;
	}
		
	// Add any remaining indices not covered by Jacobsthal sequence
	std::vector<bool> used(n + 1, false);
	for (size_t i = 0; i < order.size(); i++) {
		if (order[i] <= n)
			used[order[i]] = true;
	}
		
	for (size_t i = 1; i <= n; i++) {
		if (!used[i]) {
			order.push_back(i);
		}
	}
		
	return order;
}

std::vector<int> PmergeMe::fordJohnson(std::vector<int> vec) {
	// M1. [Initial sorting pass]
	size_t n = vec.size();
	if (n <= 1)
		return vec;

	bool hasLeftover = (n % 2 == 1);
	int leftover = 0;

	// Handle odd case: save last element
	if (hasLeftover) {
		leftover = vec[n - 1];
		hasLeftover = true;
		n--;
	}
	
	// M2. [Pairwise comparison] - Form pairs (b_i, a_i) where b_i <= a_i
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < n; i += 2) {
		if (vec[i] < vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}

	// extract 'a' values (bigger ones)
	std::vector<int> a_values;
	for (size_t i = 0; i < pairs.size(); ++i) {
		a_values.push_back(pairs[i].second);
	}

	// M3. [Recursively sort a values]
	std::vector<int> sorted_a = fordJohnson(a_values);
 
	// M4. [Reorder pairs according to sorted a values]
	std::vector<std::pair<int, int> > sorted_pairs;
	std::vector<bool> used(pairs.size(), false);
	for (size_t i = 0; i < sorted_a.size(); ++i) {
		for (size_t j = 0; j < pairs.size(); ++j) { 
			if (!used[j] && pairs[j].second == sorted_a[i]) {
				sorted_pairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}
	// M5. [Build main chain S]
	// S starts with b_1, then all a values in order
	std::vector<int> mainChain;
	if (!sorted_pairs.empty()) {
		mainChain.push_back(sorted_pairs[0].first);   // b_1	
		for (size_t i = 0; i < sorted_pairs.size(); i++) {
			mainChain.push_back(sorted_pairs[i].second);  // a_1, a_2, ..., a_n
		} 
	}
	// M6. [Insert remaining b values using Jacobsthal order]
	// Insert b_2, b_3, ..., b_n in the order defined by Jacobsthal numbers
	if (sorted_pairs.size() > 1) {
		std::vector<size_t> insertionOrder = getInsertionOrder(sorted_pairs.size() - 1);
		for (size_t idx = 0; idx < insertionOrder.size(); idx++) {
			size_t i = insertionOrder[idx]; // i goes from 2 to n
			if (i < sorted_pairs.size()) {
				int b_value = sorted_pairs[i].first;
				// Binary search limited to position of corresponding a_i
				// a_i is now at position i in mainChain (a fter b_1)
				// Find actual position of a_i in mainChain
				size_t a_pos = 0;
				for (size_t j = 0; j < mainChain.size(); j++) {
					if (mainChain[j] == sorted_pairs[i].second) {
						a_pos = j;
						break;
					} 
				}			
				insertBinaryLimited(mainChain, b_value, a_pos);
			}
		}
	}
	// insert leftover
	if (hasLeftover) {
		insertBinaryLimited(mainChain, leftover, mainChain.size());
	}
	return mainChain;
}

std::deque<int> PmergeMe::fordJohnson(std::deque<int> deq) {
	
	size_t n = deq.size();
	if (n <= 1)
		return deq;
	bool hasLeftover = (n % 2 == 1);
	int leftover = 0;
	if (hasLeftover) {
		leftover = deq[n - 1];
		hasLeftover = true;
		n--;
	}
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < n; i += 2) {
		if (deq[i] < deq[i + 1])
			pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		else
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
	}
	std::deque<int> a_values;
	for (size_t i = 0; i < pairs.size(); ++i) {
		a_values.push_back(pairs[i].second);
	}
	std::deque<int> sorted_a = fordJohnson(a_values);
	std::deque<std::pair<int, int> > sorted_pairs;
	std::deque<bool> used(pairs.size(), false);
	for (size_t i = 0; i < sorted_a.size(); ++i) {
		for (size_t j = 0; j < pairs.size(); ++j) {
			if (!used[j] && pairs[j].second == sorted_a[i]) {
				sorted_pairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}
	std::deque<int> mainChain;
	if (!sorted_pairs.empty()) {
		mainChain.push_back(sorted_pairs[0].first);  
		for (size_t i = 0; i < sorted_pairs.size(); i++) {
			mainChain.push_back(sorted_pairs[i].second);  
		}
	}
	if (sorted_pairs.size() > 1) {
		std::deque<size_t> insertionOrder = getInsertionOrderDeque(sorted_pairs.size() - 1);
		for (size_t idx = 0; idx < insertionOrder.size(); idx++) {
			size_t i = insertionOrder[idx]; 
			if (i < sorted_pairs.size()) {
				int b_value = sorted_pairs[i].first;
				
				
				
				size_t a_pos = 0;
				for (size_t j = 0; j < mainChain.size(); j++) {
					if (mainChain[j] == sorted_pairs[i].second) {
						a_pos = j;
						break;
					}
				}			
				insertBinaryLimited(mainChain, b_value, a_pos);
			}
		}
	}
	if (hasLeftover) {
		insertBinaryLimited(mainChain, leftover, mainChain.size());
	}
	return mainChain;
}


void	PmergeMe::sortVector() {
	_vector = fordJohnson(_vector);
}

void	PmergeMe::sortDeque() {
	_deque = fordJohnson(_deque);
}
