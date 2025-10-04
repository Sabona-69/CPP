#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#define VECTOR 1
#define DEQUE 2


bool isAllDegit(char *str);

class PmergeMe {
    private:
		std::vector<int> inputs;
		std::vector<int> _vector;
		std::deque<int> _deque;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &assign);
        PmergeMe& operator=(const PmergeMe &assign);

		void	parseInput(char **av);
		void	fillContainers(int type);
		void 	printContainer(const std::string& msg);
		
		std::vector<int> getVector() const;
		std::deque<int> getDeque() const;
		void sortDeque();
		void sortVector();
		std::vector<int> fordJohnson(std::vector<int> vec);
		std::deque<int>	fordJohnson(std::deque<int> deq);

		// Binary insertion with limited search range (up to maxPos)
		void insertBinaryLimited(std::vector<int>& vec, int value, size_t maxPos);
		
		// Generate Jacobsthal numbers
		std::vector<size_t> generateJacobsthal(size_t limit);
		
		// Generate insertion order based on Jacobsthal sequence
		std::vector<size_t> getInsertionOrder(size_t n);


		void insertBinaryLimited(std::deque<int>& vec, int value, size_t maxPos);
		std::deque<size_t> generateJacobsthalDeque(size_t limit);
		std::deque<size_t> getInsertionOrderDeque(size_t n);

};




#endif
