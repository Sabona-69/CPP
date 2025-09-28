# Ford-Johnson Algorithm Implementation Todo List

## Overview
Implement the Ford-Johnson algorithm (Merge-Insertion Sort) in your PmergeMe class according to Donald Knuth's description in "The Art of Computer Programming, Vol.3, Page 184".

## Phase 1: Understanding and Planning

- [ ] Research the Ford-Johnson algorithm thoroughly
  - Understand the merge-insertion concept
  - Study the Jacobsthal numbers and their role in the algorithm
  - Learn about the tournament structure used in comparisons

- [ ] Plan the implementation approach for both vector and deque containers
  - Consider the differences between vector and deque operations
  - Plan for timing measurements to compare performance

- [ ] Design helper functions and data structures needed for the algorithm
  - Functions to calculate Jacobsthal numbers
  - Structures to store comparison results and ordering information

## Phase 2: Core Algorithm Implementation

- [ ] Add template functions for Ford-Johnson sort
  - Create a function to sort pairs of elements
  - Implement the pairing phase of the algorithm
  - Handle odd-numbered elements with a special case

- [ ] Implement the merging phase
  - Build the "diamond" pattern of comparisons
  - Use binary insertion for the final sequence
  - Follow the Jacobsthal sequence for insertion order

- [ ] Integrate the Ford-Johnson sort into the PmergeMe class
  - Add sortVector() method using Ford-Johnson for vector
  - Add sortDeque() method using Ford-Johnson for deque
  - Make sure both methods use the same algorithmic approach

## Phase 3: Integration with Existing Code

- [ ] Update PmergeMe.hpp to include necessary methods
  - Add public methods: sortVector() and sortDeque()
  - Add private helper methods if needed
  - Include necessary headers for binary search

- [ ] Update PmergeMe.cpp with the new sorting methods
  - Implement the Ford-Johnson algorithm for vector
  - Implement the Ford-Johnson algorithm for deque
  - Add helper methods for Jacobsthal number generation

- [ ] Update the main function to use the new methods
  - Time the vector sorting operation
  - Time the deque sorting operation
  - Display results in the required format

## Phase 4: Testing and Validation

- [ ] Test with various input sizes
  - Small inputs (2-10 elements)
  - Medium inputs (100-1000 elements)
  - Large inputs (10000+ elements)
  - Edge cases (already sorted, reverse sorted)

- [ ] Validate correctness
  - Verify that output is properly sorted
  - Compare results with standard library sort
  - Check that both vector and deque produce identical results

- [ ] Performance validation
  - Ensure the Ford-Johnson algorithm is more efficient than standard sort for certain input sizes
  - Verify timing measurements are accurate

## Phase 5: Optimization and Cleanup

- [ ] Optimize the Jacobsthal number generation
  - Consider pre-computing values for efficiency
  - Use efficient computation methods

- [ ] Clean up code
  - Remove any debug prints or temporary variables
  - Ensure code follows good C++ practices
  - Add comments explaining the Ford-Johnson algorithm steps

- [ ] Final testing
  - Run full test suite
  - Verify all edge cases work correctly
  - Ensure no memory leaks or errors