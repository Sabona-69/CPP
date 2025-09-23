# ex02 (MutantStack) Implementation TODO List

## Phase 1: Understanding and Setup
- [ ] Read the subject.pdf requirements for ex02
- [ ] Analyze the provided main.cpp to understand expected behavior
- [ ] Identify required functionality:
  - [ ] Inherit from std::stack
  - [ ] Add iterator functionality
  - [ ] Add reverse iterator functionality
  - [ ] Maintain all stack operations

## Phase 2: Implementation
- [ ] Create MutantStack template class
  - [ ] Define template parameters (T and Container)
  - [ ] Set default container to std::deque<T>
  - [ ] Publicly inherit from std::stack<T, Container>
- [ ] Implement constructors
  - [ ] Default constructor
  - [ ] Copy constructor
  - [ ] Assignment operator
- [ ] Define iterator types
  - [ ] typedef Container::iterator as iterator
  - [ ] typedef Container::const_iterator as const_iterator
  - [ ] typedef Container::reverse_iterator as reverse_iterator
  - [ ] typedef Container::const_reverse_iterator as const_reverse_iterator
- [ ] Implement iterator methods
  - [ ] begin() method (non-const version)
  - [ ] end() method (non-const version)
  - [ ] begin() method (const version)
  - [ ] end() method (const version)
  - [ ] rbegin() method (non-const version)
  - [ ] rend() method (non-const version)
  - [ ] rbegin() method (const version)
  - [ ] rend() method (const version)

## Phase 3: Testing
- [ ] Compile with provided main.cpp
- [ ] Run basic functionality test
- [ ] Test iterator functionality
- [ ] Test reverse iterator functionality
- [ ] Verify all stack operations work
- [ ] Test with different container types

## Phase 4: Edge Cases
- [ ] Test with empty stack
- [ ] Test with single element
- [ ] Test with multiple elements
- [ ] Verify const-correctness
- [ ] Test reverse iteration

## Phase 5: Final Verification
- [ ] Check for memory leaks with valgrind/sanitizers
- [ ] Verify compliance with subject requirements
- [ ] Ensure code follows C++98 standard
- [ ] Confirm all Makefile targets work
- [ ] Verify behavior matches other standard containers