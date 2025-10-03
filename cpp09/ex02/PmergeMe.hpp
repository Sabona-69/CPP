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




};




#endif
