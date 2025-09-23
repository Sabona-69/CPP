# ex02 Issues and Edge Cases Checklist

## Current Implementation Issues

### 1. Typo in typedef
- [ ] Fix `reverse_const_iterator` -> `const_reverse_iterator`

### 2. Incorrect return types for reverse iterators
- [ ] Fix `iterator rbegin()` -> `reverse_iterator rbegin()`
- [ ] Fix `iterator rend()` -> `reverse_iterator rend()`
- [ ] Fix `const_iterator rbegin() const` -> `const_reverse_iterator rbegin() const`
- [ ] Fix `const_iterator rend() const` -> `const_reverse_iterator rend() const`

## Potential Edge Cases to Test

### 1. Empty Stack
- [ ] Test calling begin() and end() on empty stack (should be equal)
- [ ] Test calling rbegin() and rend() on empty stack (should be equal)

### 2. Single Element Stack
- [ ] Test iterator behavior with one element
- [ ] Test reverse iterator behavior with one element

### 3. Iterator Validity
- [ ] Test that iterators remain valid after stack operations
- [ ] Test incrementing iterators beyond end (undefined behavior)
- [ ] Test decrementing iterators before begin (undefined behavior)

### 4. Const-Correctness
- [ ] Test that const iterators work correctly
- [ ] Test that const iterators cannot modify elements

### 5. Different Container Types
- [ ] Test with std::deque (default)
- [ ] Test with std::vector
- [ ] Test with std::list

### 6. Memory Management
- [ ] Test for memory leaks
- [ ] Test proper destruction of objects

## Subject Requirements Verification

### 1. Inheritance
- [ ] Verify MutantStack publicly inherits from std::stack

### 2. Iterator Functionality
- [ ] Verify begin() and end() methods work correctly
- [ ] Verify rbegin() and rend() methods work correctly

### 3. Standard Stack Operations
- [ ] Verify push(), pop(), top(), size(), empty() work
- [ ] Verify copy constructor and assignment operator work

### 4. Template Parameters
- [ ] Verify template with custom type works
- [ ] Verify custom container type works

## Additional Considerations

### 1. Compiler Compatibility
- [ ] Ensure C++98 compatibility
- [ ] Check for proper template syntax (>> spacing)

### 2. Error Handling
- [ ] Verify appropriate exceptions are thrown when needed
- [ ] Test with invalid operations