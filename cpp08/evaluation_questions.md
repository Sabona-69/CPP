
# C++ Templates Module Evaluation Questions

## Regular Questions


1. What are C++ templates and why are they useful?


2. Explain the difference between function templates and class templates.

3. What is template instantiation?

4. How do you implement a template function that works with different data types?

5. What is the difference between `typename` and `class` in template declarations?

6. How do you handle exceptions in template code?

7. What does the STL stand for and what are its main components?

8. Explain the difference between sequence containers and associative containers.

9. What is the difference between `std::vector` and `std::list`?

10. How does `std::stack` work and what are its main operations?

11. Explain the concept of iterators in STL containers.

12. What are the different types of iterators in C++?

13. How would you implement a custom container that provides iterator functionality?

14. What is the difference between `iterator` and `const_iterator`?

15. Explain the iterator pattern and its use in STL.

## Tricky Questions

16. What happens when you try to use `std::find` with a container that doesn't support the required iterator type?

17. How would you handle potential overflow when calculating spans in the Span class?

18. What are the implications of inheriting from `std::stack` in the MutantStack exercise?

19. Why is it important to consider the underlying container type in the MutantStack implementation?

20. What are the potential issues with the expression `this->c` in the MutantStack implementation?

21. How would you handle the case where Span is initialized with only one number when calling shortestSpan() or longestSpan()?

22. How does the template parameter `Container = std::deque<T>` affect the MutantStack functionality?

23. What happens if you call `begin()` or `end()` on an empty MutantStack?

24. Can you use the MutantStack iterators with STL algorithms? Why or why not?

25. How would you implement the assignment operator for the Span class to handle deep copying?

26. What are the potential issues with using `unsigned int` for storing spans in the Span class?

27. What is the difference between `std::distance` and calculating span manually?

28. How would you optimize the Span class to avoid sorting the entire vector for each span calculation?

29. What are the implications of using `std::numeric_limits<T>::max()` in template code?

30. What would be the behavior if you tried to instantiate the MutantStack with a non-default-constructible type?

## Advanced Tricky Questions

31. How would you implement thread-safe access to the Span class?

32. Can you use a custom comparator with the Span class to change the ordering of elements?

33. What are the performance implications of accessing the underlying container directly via `this->c`?

34. How would you implement range-based for loops for the MutantStack?

35. What are the memory implications of storing iterators and how do they relate to the container's lifetime?

36. How would you implement a template specialization for the easyfind function?

37. What happens if you try to copy a MutantStack with a custom allocator?

38. How would you ensure exception safety in the Span class operations?

39. What are the implications of using move semantics in the MutantStack implementation?

40. How would you implement a custom iterator class if STL iterators weren't available?

---

## Answers

### Regular Questions

1. **What are C++ templates and why are they useful?**
   Templates are a feature in C++ that allows generic programming - writing code that works with multiple data types. They enable code reusability and type safety without duplicating code for each type.

2. **Explain the difference between function templates and class templates.**
   Function templates allow creating generic functions that work with different types, while class templates allow creating generic classes. Function templates are instantiated automatically by the compiler, while class templates require explicit instantiation or partial deduction.

3. **What is template instantiation?**
   Template instantiation is the process where the compiler generates concrete code from a template definition for a specific type.

4. **How do you implement a template function that works with different data types?**
   Using the template keyword followed by the template parameters in angle brackets, then defining the function as usual. Example:
   ```cpp
   template<typename T>
   T max(T a, T b) {
       return a > b ? a : b;
   }
   ```

5. **What is the difference between `typename` and `class` in template declarations?**
   There is no functional difference; both can be used interchangeably in template declarations. `typename` is more general and is required when referring to nested dependent types.

6. **How do you handle exceptions in template code?**
   Use try-catch blocks and throw appropriate exceptions. Templates should be designed with exception safety in mind, using RAII principles and proper exception specifications when needed.

7. **What does the STL stand for and what are its main components?**
   STL stands for Standard Template Library. Its main components are containers (like vector, list, map), iterators, and algorithms (like sort, find).

8. **Explain the difference between sequence containers and associative containers.**
   Sequence containers (vector, list, deque) store elements in a linear sequence and allow access by position. Associative containers (map, set, multimap) store elements sorted by keys and allow access by key.

9. **What is the difference between `std::vector` and `std::list`?**
   vector stores elements in contiguous memory, allowing random access and efficient end insertion. list stores elements in a doubly-linked list, allowing efficient insertion/deletion anywhere but only sequential access.

10. **How does `std::stack` work and what are its main operations?**
    std::stack is a container adapter that works on LIFO (Last In, First Out) principle. Its main operations are push(), pop(), top(), empty(), and size().

11. **Explain the concept of iterators in STL containers.**
    Iterators are objects that point to elements in containers and allow traversal of the container. They act similarly to pointers and provide a way to access elements without exposing the internal structure of the container.

12. **What are the different types of iterators in C++?**
    The main types are: input iterator, output iterator, forward iterator, bidirectional iterator, and random access iterator, each providing different levels of functionality.

13. **How would you implement a custom container that provides iterator functionality?**
    By inheriting from an appropriate STL container or implementing the appropriate iterator types and methods (begin(), end(), rbegin(), rend()).

14. **What is the difference between `iterator` and `const_iterator`?**
    iterator allows modification of the element it points to, while const_iterator only allows reading and not modification of the element.

15. **Explain the iterator pattern and its use in STL.**
    The iterator pattern provides a way to access elements of a container sequentially without exposing the underlying representation. In STL, it provides a uniform interface for traversing different types of containers.

### Tricky Questions

16. **What happens when you try to use `std::find` with a container that doesn't support the required iterator type?**
    Compilation error. std::find requires input iterators, so the container must support at least that level of iterator functionality.

17. **How would you handle potential overflow when calculating spans in the Span class?**
    Use appropriate data types (like long long or unsigned long) and check for overflow conditions before performing calculations. Use std::numeric_limits for boundary checks.

18. **What are the implications of inheriting from `std::stack` in the MutantStack exercise?**
    It's public inheritance, so all public methods of std::stack are accessible. The derived class gains access to the protected member 'c' (the underlying container) which allows implementing iterator functionality.

19. **Why is it important to consider the underlying container type in the MutantStack implementation?**
    Because the iterator types depend on the container. std::stack uses std::deque by default, so iterator, const_iterator, reverse_iterator, and const_reverse_iterator types are determined by the underlying container.

20. **What are the potential issues with the expression `this->c` in the MutantStack implementation?**
    The `this->` is necessary because `c` is a dependent name in a template. Without it, the compiler might not find the protected member `c` from the base class.

21. **How would you handle the case where Span is initialized with only one number when calling shortestSpan() or longestSpan()?**
    Throw an exception since it's impossible to calculate a span with only one number (a span requires at least two elements).

22. **How does the template parameter `Container = std::deque<T>` affect the MutantStack functionality?**
    It allows users to specify a different underlying container (like std::vector or std::list), which would change the performance characteristics and available operations.

23. **What happens if you call `begin()` or `end()` on an empty MutantStack?**
    It would return valid iterators that are equal to each other, representing an empty range. Dereferencing them would be undefined behavior.

24. **Can you use the MutantStack iterators with STL algorithms? Why or why not?**
    Yes, because MutantStack exposes the underlying container's iterators, which are compatible with STL algorithms.

25. **How would you implement the assignment operator for the Span class to handle deep copying?**
    By copying all elements from the source vector to the destination vector, ensuring proper memory management and exception safety.

26. **What are the potential issues with using `unsigned int` for storing spans in the Span class?**
    Possible integer overflow with large numbers, and inability to represent negative spans (though spans are always positive by definition).

27. **What is the difference between `std::distance` and calculating span manually?**
    std::distance works with any iterator type and calculates the distance between two iterators, while manual span calculation typically involves finding the difference between two specific values in a container.

28. **How would you optimize the Span class to avoid sorting the entire vector for each span calculation?**
    Keep track of min/max values as elements are added, updating them incrementally rather than sorting the entire vector each time.

29. **What are the implications of using `std::numeric_limits<T>::max()` in template code?**
    The type T must be numeric or have specializations defined. This can cause compilation errors with non-numeric types.

30. **What would be the behavior if you tried to instantiate the MutantStack with a non-default-constructible type?**
    It would fail to compile if the underlying container requires default construction of its elements.

### Advanced Tricky Questions

31. **How would you implement thread-safe access to the Span class?**
    Use mutexes to synchronize access to the internal container, or implement atomic operations where appropriate.

32. **Can you use a custom comparator with the Span class to change the ordering of elements?**
    Not directly with the current implementation, but you could modify the class to accept a comparator in the constructor and use std::sort with that comparator.

33. **What are the performance implications of accessing the underlying container directly via `this->c`?**
    It bypasses the stack's interface but provides direct access to the container's functionality. This can be faster but removes the LIFO constraint that defines a stack.

34. **How would you implement range-based for loops for the MutantStack?**
    The current implementation already supports range-based for loops because it provides begin() and end() methods that return iterators.

35. **What are the memory implications of storing iterators and how do they relate to the container's lifetime?**
    Storing iterators can lead to dangling pointers if the container is destroyed or reallocated. Iterators should not outlive the container.

36. **How would you implement a template specialization for the easyfind function?**
    Define a specific implementation for particular types while keeping the general template for other types:
    ```cpp
    template<>
    void easyfind<int>(std::vector<int>& container, int value) { /* specific implementation */ }
    ```

37. **What happens if you try to copy a MutantStack with a custom allocator?**
    The copy would use the same allocator type, and the underlying container would be copied using that allocator.

38. **How would you ensure exception safety in the Span class operations?**
    Use RAII, implement the strong exception safety guarantee, and ensure proper cleanup in case of exceptions in methods like addNumber.

39. **What are the implications of using move semantics in the MutantStack implementation?**
    It would provide more efficient copying of the underlying container, especially for expensive-to-copy types, by transferring resources instead of copying them.

40. **How would you implement a custom iterator class if STL iterators weren't available?**
    Create a class that implements the required iterator operations: operator*, operator++, operator!=, etc., following the appropriate iterator concept (input, forward, bidirectional, random access).