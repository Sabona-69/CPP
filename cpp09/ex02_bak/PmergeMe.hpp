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
		std::vector<size_t> generateJacobsthalSequence(size_t size);

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &assign);
        PmergeMe& operator=(const PmergeMe &assign);
		std::vector<int> getVector() const;
		std::deque<int> getDeque() const;

		void fillContainers(char **argv);
		template <typename Container>
		void sort(Container &container);
};

// Template implementation must be in header file for proper instantiation
template <typename Container>
void	PmergeMe::sort(Container &container) {
    if (container.size() <= 1)
        return;

    typedef typename Container::value_type T;

    // Step 1: Pair up consecutive elements and separate into 'larger' and 'smaller' elements
    Container larger_elements;    // The 'winners' (larger) of each comparison pair
    Container smaller_elements;   // The 'losers' (smaller) of each comparison pair 
    bool has_odd_element = false;
    T odd_element_value;
    
    typename Container::iterator it = container.begin();
    while (it != container.end()) {
        T first_val = *it++;
        if (it != container.end()) {
            T second_val = *it++;
            // Compare and order elements: ensure first_val > second_val
            if (first_val < second_val) {
                std::swap(first_val, second_val);
            }
            larger_elements.push_back(first_val);   // Larger element
            smaller_elements.push_back(second_val); // Smaller element
        } else {
            // Odd element - save for insertion at the end
            has_odd_element = true;
            odd_element_value = first_val;
        }
    }

    // Step 2: Recursively sort the 'larger' elements (main chain)
    sort(larger_elements);

    // Step 3: Generate Jacobsthal sequence for insertion order
    std::vector<size_t> jacobsthal_seq = generateJacobsthalSequence(smaller_elements.size());

    // Step 4: Insert 'smaller' elements into the sorted main chain using binary search
    for (typename std::vector<size_t>::const_iterator it_idx = jacobsthal_seq.begin(); it_idx != jacobsthal_seq.end(); ++it_idx) {
        size_t insertion_order_idx = *it_idx;
        if (insertion_order_idx < smaller_elements.size()) {
            // Need to get the element corresponding to the insertion order, not by sequence
            typename Container::const_iterator temp_it = smaller_elements.begin();
            std::advance(temp_it, insertion_order_idx);
            T element_to_insert = *temp_it;

            // Find position in main chain using binary search
            typename Container::iterator pos = std::lower_bound(larger_elements.begin(), larger_elements.end(), element_to_insert);
            larger_elements.insert(pos, element_to_insert);
        }
    }

    // Step 5: If there was an odd element, insert it using binary search
    if (has_odd_element) {
        typename Container::iterator pos = std::lower_bound(larger_elements.begin(), larger_elements.end(), odd_element_value);
        larger_elements.insert(pos, odd_element_value);
    }

    // Step 6: Replace the original container with the sorted result
    container = larger_elements;
}

bool isAllDegit(char *str);

template <typename Container>
void printContainer(const Container &container);

#endif
