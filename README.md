# C++ Programming Modules

A comprehensive collection of C++ programming exercises covering fundamental to advanced concepts. This repository contains modules cpp00 through cpp09, each focusing on specific aspects of C++ programming.

## 📚 Table of Contents

- [About](#about)
- [Modules Overview](#modules-overview)
- [Getting Started](#getting-started)
- [Compilation](#compilation)
- [Project Structure](#project-structure)
- [Learning Objectives](#learning-objectives)
- [Requirements](#requirements)
- [Author](#author)

## 🎯 About

This repository contains a series of C++ programming exercises designed to build a solid foundation in C++ programming. Each module progressively introduces new concepts, from basic syntax to advanced object-oriented programming principles.

## 📖 Modules Overview

### Module 00: Namespace, Class, Member Functions, stdio Stream, Initialization Lists, Static, Const
- **ex00**: Megaphone - Basic I/O and string manipulation
- **ex01**: My Awesome PhoneBook - Introduction to classes
- **ex02**: The Job Of Your Dreams - More class implementation

### Module 01: Memory Allocation, Pointers to Members, References, Switch Statement
- **ex00**: BraiiiiiiinnnzzzZ - Memory management and object creation
- **ex01**: Moar Brainz! - Dynamic memory allocation
- **ex02**: HI THIS IS BRAIN - Pointers and references
- **ex03**: Unnecessary Violence - Weapon class implementation
- **ex04**: Sed is for Losers - File manipulation
- **ex05**: Harl 2.0 - Function pointers
- **ex06**: Harl Filter - Switch statements

### Module 02: Ad-hoc Polymorphism, Operator Overloading, Orthodox Canonical Class Form
- **ex00**: My First Class in Orthodox Canonical Form
- **ex01**: Towards a More Useful Fixed-point Number Class
- **ex02**: Now We're Talking
- **ex03**: BSP (Binary Space Partitioning)

### Module 03: Inheritance
- **ex00**: Aaaaand... OPEN! - Basic inheritance
- **ex01**: Serena, my Love! - Extended class features
- **ex02**: Repetitive Work - Multiple inheritance
- **ex03**: Now It's Weird! - Diamond inheritance problem

### Module 04: Subtype Polymorphism, Abstract Classes, Interfaces
- **ex00**: Polymorphism basics
- **ex01**: I Don't Want to Set the World on Fire
- **ex02**: Abstract Classes
- **ex03**: Interfaces and Deep Copies

### Module 05: Repetition and Exceptions
- **ex00**: Mommy, When I Grow Up, I Want to Be a Bureaucrat!
- **ex01**: Form Up, Maggots!
- **ex02**: No, You Need Form 28B, Not 28C...
- **ex03**: At Least This Beats Coffee-making

### Module 06: C++ Casts
- **ex00**: Conversion of Scalar Types
- **ex01**: Serialization
- **ex02**: Identify Real Type

### Module 07: C++ Templates
- Exploration of template programming and generic functions

### Module 08: Templated Containers, Iterators, Algorithms
- Working with STL containers and algorithms

### Module 09: STL
- Advanced Standard Template Library usage

## 🚀 Getting Started

### Prerequisites

- C++ compiler with C++98 standard support (g++ or clang++)
- Make utility

### Clone the Repository

```bash
git clone https://github.com/yourusername/cpp-modules.git
cd cpp-modules
```

## 🔨 Compilation

Each exercise has its own Makefile. To compile an exercise:

```bash
cd cpp00/ex00
make
```

This will generate an executable. Run it with:

```bash
./executable_name
```

To clean object files:

```bash
make clean
```

To remove all generated files:

```bash
make fclean
```

To recompile everything:

```bash
make re
```

## 📁 Project Structure

```
CPP/
├── cpp00/          # Module 00 exercises
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
├── cpp01/          # Module 01 exercises
│   ├── ex00/
│   ├── ex01/
│   ├── ex02/
│   ├── ex03/
│   ├── ex04/
│   ├── ex05/
│   └── ex06/
├── cpp02/          # Module 02 exercises
│   ├── ex00/
│   ├── ex01/
│   ├── ex02/
│   └── ex03/
├── cpp03/          # Module 03 exercises
├── cpp04/          # Module 04 exercises
├── cpp05/          # Module 05 exercises
├── cpp06/          # Module 06 exercises
├── cpp07/          # Module 07 exercises
├── cpp08/          # Module 08 exercises
├── cpp09/          # Module 09 exercises
└── README.md       # This file
```

## 🎓 Learning Objectives

Throughout these modules, you will learn:

- **Object-Oriented Programming**: Classes, inheritance, polymorphism, encapsulation
- **Memory Management**: Stack vs heap, RAII, smart pointers
- **Advanced C++ Features**: Templates, STL, exception handling, operator overloading
- **Best Practices**: Orthodox Canonical Form, const correctness, proper resource management
- **Design Patterns**: Factory, singleton, and other common patterns

## 📋 Requirements

- All code must compile with:
  ```bash
  c++ -Wall -Wextra -Werror -std=c++98
  ```
- No memory leaks
- Proper use of Orthodox Canonical Form where applicable
- Clean separation between interface (.hpp) and implementation (.cpp)

## 💡 Key Concepts

### Orthodox Canonical Form
Each class should implement:
- Default constructor
- Copy constructor
- Assignment operator
- Destructor

### Memory Management
- Proper allocation and deallocation
- Understanding of stack vs heap
- RAII principles

### Compilation Flags
- `-Wall`: Enable all warnings
- `-Wextra`: Enable extra warnings
- `-Werror`: Treat warnings as errors
- `-std=c++98`: Use C++98 standard

## 🤝 Contributing

This is a personal learning repository. However, suggestions and feedback are welcome!

## 📝 License

This project is created for educational purposes.

## 👤 Author

**Your Name**
- GitHub: [@yourusername](https://github.com/yourusername)

---

⭐ If you found this helpful, please consider giving it a star!

## 📚 Additional Resources

- [C++ Reference](https://en.cppreference.com/)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [Learn CPP](https://www.learncpp.com/)
