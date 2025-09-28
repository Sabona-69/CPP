#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <algorithm>



class PmergeMe {
    private:
		std::vector<int> _vector;
		std::deque<int> _deque;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &assign);
        PmergeMe& operator=(const PmergeMe &assign);

		void printContainer(const std::string& msg);
		
		std::vector<int> getVector() const;
		std::deque<int> getDeque() const;
		void fillContainers(char **argv);
		void sortDeque();
		void sortVector();

};


bool isAllDegit(char *str);

#endif
