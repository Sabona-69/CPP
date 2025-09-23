# ex02 (MutantStack) Implementation Guide

## Subject Requirements Overview
- Create a MutantStack class that inherits from std::stack
- Add iterator functionality to allow traversal of stack elements
- Maintain all standard stack operations (push, pop, top, size, etc.)
- Should behave like other standard containers when used with iterators

## Key Concepts to Understand
1. **std::stack container adapter**: A container adapter that provides stack functionality
2. **Template specialization**: Using template parameters for type and container
3. **Inheritance**: Public inheritance from std::stack
4. **Iterator access**: Accessing iterators from the underlying container
5. **Reverse iterators**: Providing rbegin() and rend() for reverse iteration

## Implementation Steps

### 1. Class Declaration
- Create a template class MutantStack with two template parameters:
  - T: The type of elements
  - Container: The underlying container type (default: std::deque<T>)
- Publicly inherit from std::stack<T, Container>

### 2. Constructor Implementation
- Default constructor
- Copy constructor
- Assignment operator

### 3. Iterator Type Definitions
- Define iterator as Container::iterator
- Define const_iterator as Container::const_iterator
- Define reverse_iterator as Container::reverse_iterator
- Define const_reverse_iterator as Container::const_reverse_iterator

### 4. Iterator Methods
- begin(): Return iterator to the beginning of the container
- end(): Return iterator to the end of the container
- rbegin(): Return reverse iterator to the reverse beginning of the container
- rend(): Return reverse iterator to the reverse end of the container
- Both const and non-const versions of all methods

### 5. Accessing the Underlying Container
- In std::stack, the underlying container is typically protected member 'c'
- Use this->c to access the container in your methods

## Important Details

### Template Syntax
```cpp
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
    // Implementation
};
```

### Iterator Access
```cpp
// Forward iterators
iterator begin() { return this->c.begin(); }
iterator end() { return this->c.end(); }
const_iterator begin() const { return this->c.begin(); }
const_iterator end() const { return this->c.end(); }

// Reverse iterators
reverse_iterator rbegin() { return this->c.rbegin(); }
reverse_iterator rend() { return this->c.rend(); }
const_reverse_iterator rbegin() const { return this->c.rbegin(); }
const_reverse_iterator rend() const { return this->c.rend(); }
```

## Testing Your Implementation
1. Test basic stack operations (push, pop, top, size)
2. Test iterator functionality (begin/end)
3. Test reverse iterator functionality (rbegin/rend)
4. Test with different container types (std::deque, std::vector, std::list)
5. Test edge cases (empty stack, single element)
6. Verify compatibility with std::stack interface
7. Compare behavior with other standard containers

## Common Pitfalls to Avoid
1. Forgetting to include necessary headers (<stack>, <deque>, etc.)
2. Incorrect template syntax (especially with >> in C++98)
3. Not providing both const and non-const iterator methods
4. Not implementing reverse iterators (rbegin/rend)
5. Incorrect access to the protected container member
6. Missing or incorrect type definitions

## Files to Create/Modify
- MutantStack.hpp: Your MutantStack class implementation
- You can use the provided main.cpp for testingr