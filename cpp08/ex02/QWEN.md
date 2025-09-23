# C++ Module 08 - C++ Templates

This directory contains the exercises for C++ Module 08, which focuses on templates and STL containers in C++.

## Project Overview

This is a C++ educational project consisting of three exercises that demonstrate different aspects of C++ templates and STL:

1. **ex00 - EasyFind**: Implementation of a template function that searches for a value in a container
2. **ex01 - Span**: Implementation of a class that stores integers and can find the shortest and longest spans between them
3. **ex02 - MutantStack**: Implementation of a stack class that inherits from std::stack and provides iterator functionality

## Directory Structure

```
.
├── en.subject.pdf          # Project requirements and specifications
├── ex00/                   # Exercise 00 - EasyFind
│   ├── easyfind.hpp        # Template function implementation
│   ├── main.cpp            # Test program
│   └── Makefile            # Build configuration
├── ex01/                   # Exercise 01 - Span
│   ├── Span.hpp            # Span class declaration
│   ├── Span.cpp            # Span class implementation
│   ├── main.cpp            # Test program
│   └── Makefile            # Build configuration
└── ex02/                   # Exercise 02 - MutantStack
    ├── MutantStack.hpp     # MutantStack class declaration and implementation
    ├── main.cpp            # Test program
    ├── Makefile            # Build configuration
    ├── IMPLEMENTATION_GUIDE.md  # Implementation guide for MutantStack
    └── TODO.md             # Implementation checklist
```

## Building and Running

### Exercise 00 - EasyFind
```bash
cd ex00
make        # Compile the program
./easy      # Run the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild everything
```

### Exercise 01 - Span
```bash
cd ex01
make        # Compile the program
./span      # Run the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild everything
```

### Exercise 02 - MutantStack
```bash
cd ex02
make        # Compile the program
./stack     # Run the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild everything
```

## Exercise Details

### ex00 - EasyFind
Implements a template function `easyfind` that takes a container and a value to find. It uses `std::find` to locate the value and throws an exception if not found.

### ex01 - Span
Implements a `Span` class that can store up to N unsigned integers and provides methods to calculate:
- `shortestSpan()`: The shortest distance between any two numbers
- `longestSpan()`: The longest distance between any two numbers

### ex02 - MutantStack
Implements a `MutantStack` class that inherits from `std::stack` and provides iterator functionality:
- `begin()`/`end()`: Forward iterators
- `rbegin()`/`rend()`: Reverse iterators

## Development Guidelines

- All code follows C++98 standard
- Compile with `-Wall -Wextra -Werror` flags
- Use proper exception handling
- Memory management is handled automatically with RAII principles
- All classes implement proper constructors, destructors, and assignment operators

## Testing

Each exercise includes a main.cpp file with test cases that demonstrate the functionality:

- **ex00**: Tests finding existing and non-existing values in different container types
- **ex01**: Tests span calculations with various data sets including edge cases
- **ex02**: Tests iterator functionality with stack operations

## Dependencies

- C++98 compatible compiler (e.g., g++, clang++)
- Standard C++ STL library
- Make build system