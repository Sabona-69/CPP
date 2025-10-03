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

std::vector<int> PmergeMe::fordJohnson(std::vector<int> vec) {
	if (vec.size() <= 1)
		return vec;

	bool hasLeftover = false;
	int leftover = 0;
	size_t n = vec.size();

	if (n % 2 == 1) {
		leftover = vec[n - 1];
		hasLeftover = true;
		n--;
	}
	
	// form pairs (b, a) with b < a
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

	// recursively sort 'a' values	
	std::vector<int> sorted_a = fordJohnson(a_values);
	
	// sort pairs  into sorted_pairs to match sorted_a
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
	// build main = [b1] + [a1, a2, ..., ak]
	std::vector<int> mainChain;
	mainChain.push_back(sorted_pairs[0].first);
	for (size_t i = 0; i < sorted_pairs.size(); ++i) {
		mainChain.push_back(sorted_pairs[i].second);
	}

	// build pend = [b2, b3, ..., bk]
	std::vector<int> pend;
	for (size_t i = 1; i < sorted_pairs.size(); ++i) {
		pend.push_back(sorted_pairs[i].first);
	}

	// jacobsthal-inspired insertion order: [1,0,3,2,5,4,...]
	std::vector<int> insertOrder;
	for (int i = 1; i < (int)pend.size(); i += 2) {
		insertOrder.push_back(i);
		insertOrder.push_back(i - 1);
	}
	if (pend.size() % 2 == 1 && !pend.empty()) {
		insertOrder.push_back(pend.size() - 1);
	}

	// insert pend elements
	for (size_t idx = 0; idx < insertOrder.size(); ++idx) {
		int val = pend[insertOrder[idx]];
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
		mainChain.insert(it, val);
	} 

	// insert leftover
	if (hasLeftover) {
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
		mainChain.insert(it, leftover);
	}

	return mainChain;
}

std::deque<int> PmergeMe::fordJohnson(std::deque<int> deq) {
	if (deq.size() <= 1)
		return deq;

	bool hasLeftover = false;
	int leftover = 0;
	size_t n = deq.size();

	if (n % 2 == 1) {
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
	mainChain.push_back(sorted_pairs[0].first);
	for (size_t i = 0; i < sorted_pairs.size(); ++i) {
		mainChain.push_back(sorted_pairs[i].second);
	}
	std::deque<int> pend;
	for (size_t i = 1; i < sorted_pairs.size(); ++i) {
		pend.push_back(sorted_pairs[i].first);
	}
	std::deque<int> insertOrder;
	for (int i = 1; i < (int)pend.size(); i += 2) {
		insertOrder.push_back(i);
		insertOrder.push_back(i - 1);
	}
	if (pend.size() % 2 == 1 && !pend.empty()) {
		insertOrder.push_back(pend.size() - 1);
	}
	for (size_t idx = 0; idx < insertOrder.size(); ++idx) {
		int val = pend[insertOrder[idx]];
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
		mainChain.insert(it, val);
	} 
	if (hasLeftover) {
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
		mainChain.insert(it, leftover);
	}
	return mainChain;
}


void	PmergeMe::sortVector() {
	_vector = fordJohnson(_vector);
}

void	PmergeMe::sortDeque() {
	_deque = fordJohnson(_deque);
}
