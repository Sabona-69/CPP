#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <climits>



class PmergeMe {
    private:
		std::vector<int> _vector;
		std::deque<int> _deque;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &assign);
        PmergeMe& operator=(const PmergeMe &assign);
		void fillContainers(char **argv);
};

#endif
