# 📌 Key Concepts in CPP Module 01

## 1. Main Topics
- **Memory Allocation**  
- **Pointers to Members**  
- **References**  
- **Switch Statement**  

---

## 2. Essential C++ Knowledge for the Project
### 🔹 Memory Management
- How does memory allocation work in C++?
- What is the difference between `new` and `malloc`?
- Why should we use `delete` with `new`?
- How can we prevent **Memory Leaks**?

### 🔹 Pointers and References
- What is the difference between a **Pointer** and a **Reference**?
- How do we use `Pointer to a Member`?
- Why are **References** useful in C++?
- How do we manipulate variables using pointers?

### 🔹 The `switch` Statement
- What is the difference between `if-else` and `switch`?
- How does `switch-case` work?
- Why do we use `break` in `switch`?
- What is the purpose of the `default` case?

---

## 3. Exercises and What You Should Know
### 🧠 Ex00 - `BraiiiiiiinnnzzzZ` (The First Zombie)
- How to design the `Zombie` class?
- Difference between `newZombie()` and `randomChump()`?
- Why does `newZombie()` return a `pointer`?
- How to handle **Destructors** to delete zombies?

### 🧟 Ex01 - `Moar brainz!` (Zombie Horde)
- How to create a **Horde of Zombies** using **Dynamic Allocation**?
- How to manage zombie memory?
- Why do we need `delete[]` after using `new[]`?

### 🧠 Ex02 - `HI THIS IS BRAIN` (Pointers & References)
- Difference between **Pointers** and **References** when handling data?
- How to get the memory address of a variable?
- Why do `stringPTR` and `stringREF` give the same value?

### ⚔️ Ex03 - `Unnecessary Violence` (Weapons & Characters)
- How to design the `Weapon` class?
- Difference between `HumanA` and `HumanB`?
- Why does `HumanA` need a weapon in its constructor?
- How can `HumanB` exist without a weapon?

### 📄 Ex04 - `Sed is for losers` (Text Processing)
- How to open and modify files in C++?
- Why is `std::string::replace` forbidden?
- How to replace `s1` with `s2` in a file?
- How to handle **errors** (file not found, empty file, etc.)?

### 😡 Ex05 - `Harl 2.0` (Complaint System)
- How to design the `Harl` class using **Pointers to Member Functions**?
- Why should we use `Pointer to Function` instead of `if-else`?
- How to call `debug()`, `info()`, `warning()`, `error()` efficiently?

### 🔇 Ex06 - `Harl Filter` (Filtering Complaints)
- How to make `Harl` filter **complaint levels**?
- How does `switch-case` simplify message handling?
- How to handle **invalid inputs**?

---

## 📌 Questions That Might Be Asked in Defense
### 🟢 Memory Management Questions
1. How does `new` allocate memory?
2. Why is `delete` necessary with `new`?
3. How can we prevent **Memory Leaks**?
4. What is the difference between `stack` and `heap` memory allocation?

### 🔵 Pointers and References Questions
5. Why can’t a `Reference` be `NULL`?
6. How does a `Pointer` provide more control compared to a `Reference`?
7. What is the difference between `const int*` and `int* const`?
8. How to use `Pointers to Member Functions`?

### 🟠 `switch` Statement Questions
9. Why is `switch-case` faster than `if-else`?
10. What happens if we forget `break` in `case`?
11. Why is `default` used in `switch`?

### 🟣 Zombie Class Questions
12. Difference between `newZombie()` and `randomChump()`?
13. Why does `newZombie()` return a `pointer`, while `randomChump()` creates zombies on the `stack`?

### 🟡 Weapon & Human Questions
14. Why does `HumanA` require a `Weapon` in the constructor?
15. How can `HumanB` exist without a weapon?
16. What is the difference between passing `Weapon` as a `Reference` vs. a `Pointer`?

### 🟠 Text Processing (File Handling) Questions
17. How to open and read a file in C++?
18. How to write to a new file?
19. How to handle errors when working with files?

### 🔴 Harl & Filters Questions
20. Why are `Pointers to Member Functions` useful?
21. How to use `switch` to filter complaints?

---

## 📌 Important Terms You Should Know
| **Term** | **Definition** |
|------------|------------|
| **Memory Allocation** | Allocating memory in C++ using `new` and `delete`. |
| **Pointer** | A variable that stores the address of another variable in memory. |
| **Reference** | An alias for another variable without its own memory address. |
| **Stack vs Heap** | `Stack` is fast and managed by the **compiler**, while `Heap` is managed by the **programmer**. |
| **Destructor** | A function that is called automatically when an object is deleted. |
| **Switch Statement** | A way to execute code based on a specific `case` value. |
| **File Handling** | Managing file operations (reading, writing, modifying). |
| **Pointer to Member Function** | A pointer that refers to a function inside a class. |

---
