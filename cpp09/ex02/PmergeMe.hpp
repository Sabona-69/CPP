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
		std::vector<int> getVector() const;
		std::deque<int> getDeque() const;

		void fillContainers(char **argv);
	
};


bool isAllDegit(char *str);

template <typename Container>
void printContainer(const Container &container);

#endif
