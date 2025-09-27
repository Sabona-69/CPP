# PmergeMe Guide: Understanding the Ford-Johnson Algorithm

## Table of Contents
1. [Introduction to PmergeMe](#introduction)
2. [The Ford-Johnson Algorithm (Merge-Insertion Sort)](#ford-johnson)
3. [Algorithm Complexity](#complexity)
4. [Algorithm Steps Explained](#steps)
5. [Visualizations](#visualizations)
6. [Implementation Details](#implementation)
7. [Performance Comparison](#performance)
8. [Coding Tips](#coding-tips)

## Introduction to PmergeMe {#introduction}

The PmergeMe project requires you to implement the Ford-Johnson algorithm, also known as Merge-Insertion sort. This is one of the most efficient comparison-based sorting algorithms in terms of the number of comparisons it performs in the worst case.

### What is PmergeMe?
- PmergeMe stands for "Pmerge Me" (the student implementing it)
- It's an implementation of the Ford-Johnson algorithm
- The goal is to sort a sequence of positive integers using the Ford-Johnson algorithm
- Compare the performance with other sorting algorithms like std::sort

## The Ford-Johnson Algorithm (Merge-Insertion Sort) {#ford-johnson}

The Ford-Johnson algorithm is a comparison-based sorting algorithm that combines merge sort and insertion sort principles to minimize the number of comparisons. It was developed by Lester Ford Jr. and Selmer Johnson in 1959.

### Why is it Special?
- It uses the minimum possible number of comparisons (very close to the theoretical lower bound)
- It has a worst-case complexity of O(n log n) but with a smaller constant factor than typical merge sort
- It's particularly effective when the cost of comparisons is high

## Algorithm Complexity {#complexity}

- Time Complexity: O(n log n) in all cases
- Space Complexity: O(n) additional space
- Number of comparisons: Close to the information-theoretic lower bound of log₂(n!)

For comparison, the theoretical lower bound on the number of comparisons needed is:
- log₂(n!) ≈ n*log₂(n) - 1.443*n + O(log n)

The Ford-Johnson algorithm achieves: n*log₂(n) - 1.415*n + O(log n)

## Algorithm Steps Explained {#steps}

The Ford-Johnson algorithm consists of five main phases:

### Phase 1: Pairwise Comparisons
- Take pairs of consecutive elements (1,2), (3,4), (5,6), etc.
- For each pair, find which element is larger and which is smaller
- Put the larger elements in one array (larger array), smaller elements in another (smaller array)
- If there's an odd element at the end, leave it aside for now

```
Example: [5, 2, 8, 1, 9, 3, 7]

After pairwise comparisons:
Larger array: [5, 8, 9, 7]  (the winners of each pair)
Smaller array: [2, 1, 3, ?]  (the losers of each pair) 
Extra element: 7 (if any)
```

### Phase 2: Recursively Sort the Larger Elements
- Recursively sort the "larger" array using the same Ford-Johnson algorithm
- This becomes our "main chain" or "Jacobsthal chain"

```
Larger array: [5, 8, 9, 7]
After sorting: [5, 7, 8, 9]
Main chain: [5, 7, 8, 9]
```

### Phase 3: Jacobsthal Numbers and Binary Insertion Sequence
- Create a sequence of positions based on Jacobsthal numbers
- Jacobsthal number: J(n) = (2^n - (-1)^n) / 3
- J(1)=1, J(2)=1, J(3)=3, J(4)=5, J(5)=11, J(6)=21, etc.
- Use these numbers to determine the order in which we'll insert smaller elements

The insertion sequence follows this pattern:
- 1st element to insert: J(1) = 1 → insert at position 1
- 2nd element to insert: J(2) = 1 → insert at position 1  
- 3rd & 4th elements to insert: J(3) = 3 → insert at positions 3, 2
- 5th to 8th elements to insert: J(4) = 5 → insert at positions 5, 4, 6, 3
- And so on...

### Phase 4: Binary Insertion
- Take elements from the "smaller" array in the order determined by Jacobsthal numbers
- Use binary search to insert each element into the main chain at the correct position
- This minimizes the number of comparisons needed

### Phase 5: Include the Extra Element (if any)
- If there was an odd element left from the beginning, insert it using binary search

## Visualizations {#visualizations}

### ASCII Visualization of Pairwise Comparison Phase:

```
Original sequence: [5, 2, 8, 1, 9, 3, 7, 4]

Initial:    [5]  [2]  [8]  [1]  [9]  [3]  [7]  [4]
             |     |    |     |    |     |    |     |
            win   lose  win  lose  win  lose  win  lose
             |     |    |     |    |     |    |     |
Result:      [5]------[2]  [8]------[1]  [9]------[3]  [7]------[4]
              |           |           |           |
           larger      smaller     larger      smaller

Larger array: [5, 8, 9, 7]
Smaller array: [2, 1, 3, 4]
```

### ASCII Visualization of Main Chain Building:

```
Step 1: Sorting larger array [5, 8, 9, 7]
         After sorting: [5, 7, 8, 9] ← This is our main chain

Step 2: Inserting elements from smaller array using binary search

Main chain before insertions: [5, 7, 8, 9]

Insertion order based on Jacobsthal numbers:
- Insert element at position 1: [2] → Binary search finds position between 5 and 7
  Result: [2, 5, 7, 8, 9]

- Insert element at position 1: [1] → Binary search finds position before 2  
  Result: [1, 2, 5, 7, 8, 9]

- Insert element at position 3: [3] → Binary search finds position between 2 and 5
  Result: [1, 2, 3, 5, 7, 8, 9]

- Insert element at position 2: [4] → Binary search finds position between 3 and 5
  Final result: [1, 2, 3, 4, 5, 7, 8, 9]
```

### Jacobsthal Numbers Visualization:

```
Jacobsthal Numbers Pattern:
J(0) = 0
J(1) = 1  
J(2) = 1
J(3) = 3
J(4) = 5
J(5) = 11
J(6) = 21
...

Ranges for insertion:
- Insert 1 element at position J(1) = 1
- Insert 1 element at position J(2) = 1  
- Insert 2 elements at positions J(3) = 3, then 2
- Insert 4 elements at positions J(4) = 5, 4, 6, 3
- Insert 8 elements at positions J(5) = 11, 10, 12, 9, 13, 8, 14, 7
- And so on...
```

## Implementation Details {#implementation}

### Data Structures to Use:
1. Two containers: `std::vector` and `std::deque`
2. For each container, implement the Ford-Johnson algorithm
3. Measure time for each operation

### Key Implementation Functions:

```cpp
class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;
    
    // Internal methods for implementing Ford-Johnson
    template<typename Container>
    Container fordJohnsonSort(Container &container);

    template<typename Container>  
    Container mergeInsertSort(Container &sequence);

    template<typename T>
    void binaryInsert(T &container, typename T::value_type element);

public:
    PmergeMe();
    PmergeMe(char **input, int size);
    ~PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe& operator=(const PmergeMe &src);

    void sort();
    void print() const;
};
```

### Algorithm Implementation Steps:

1. **Pairwise Comparison Phase:**
```cpp
// Create pairs and separate larger from smaller elements
std::vector<int> larger, smaller;
for (size_t i = 0; i < sequence.size(); i += 2) {
    if (i + 1 < sequence.size()) {
        if (sequence[i] > sequence[i + 1]) {
            larger.push_back(sequence[i]);
            smaller.push_back(sequence[i + 1]);
        } else {
            larger.push_back(sequence[i + 1]);
            smaller.push_back(sequence[i]);
        }
    } else {
        // Handle odd element
        extra_element = sequence[i];
    }
}
```

2. **Recursive Sort of Larger Elements:**
```cpp
// Recursively sort the larger elements
std::vector<int> sorted_larger = fordJohnsonSort(larger);
```

3. **Binary Insertion of Smaller Elements:**
```cpp
// Use binary search to insert smaller elements in order
for (auto& element : smaller_in_jacobsthal_order) {
    binaryInsert(sorted_larger, element);
}
```

## Performance Comparison {#performance}

### Expected Results:
- Ford-Johnson should perform fewer comparisons than std::sort
- However, it may have higher constant factors due to more complex logic
- In practice, std::sort (intro sort) might be faster due to better cache locality
- The advantage of Ford-Johnson is more apparent when comparison operations are expensive

### Timing Your Implementation:
Use `std::clock()` or `<sys/time.h>` to measure performance:

```cpp
#include <ctime>

clock_t start = clock();
// perform sorting
clock_t end = clock();
double time_used = double(end - start) / CLOCKS_PER_SEC;
```

## Coding Tips {#coding-tips}

### 1. Handling Different Container Types
```cpp
template<typename Container>
Container PmergeMe::mergeInsertSort(Container &container) {
    // Your implementation here
    // Will work for both std::vector and std::deque
}
```

### 2. Avoiding Common Mistakes
- Be careful with iterator invalidation when working with vectors during insertion
- Pay attention to the order of elements when building Jacobsthal sequence
- Don't forget to handle the case where the initial sequence has an odd number of elements

### 3. Debugging Tips
- Use a small sequence first (e.g., 5-8 elements) to verify your logic
- Print intermediate results to ensure each phase is working correctly
- Compare results with std::sort to verify correctness

### 4. Memory Management
- The Ford-Johnson algorithm needs additional space for the pairs
- Make sure to properly handle memory in your canonical class form
- Watch out for unnecessary copies that might impact performance

## Summary

The PmergeMe project challenges you to implement one of the most theoretically efficient comparison-based sorting algorithms. While it's more complex than simpler algorithms like quicksort or mergesort, it has the advantage of performing close to the theoretical minimum number of comparisons.

The key to success is understanding the 5 phases:
1. Pairwise comparisons to separate elements
2. Recursive sorting of the larger elements  
3. Using Jacobsthal numbers for optimal insertion order
4. Binary insertion of elements in optimal order
5. Handling remaining elements

Remember to implement both for std::vector and std::deque, compare performance, and maintain the canonical class form!