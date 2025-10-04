# CPP09 Testing Suite - Index

## 📚 All Created Test Files

### Executable Test Scripts
1. **test_all.sh** - Complete automated test suite (bash)
2. **tricky_tests.sh** - Edge cases and permission tests (bash)
3. **run_tests.py** - Python-based test runner

### Documentation Files
4. **README_TESTS.md** - Main testing documentation (START HERE)
5. **TESTING_GUIDE.md** - Complete manual testing guide
6. **TRICKY_TESTS.md** - Advanced edge cases documentation
7. **MANUAL_TEST_COMMANDS.txt** - Ready-to-copy commands
8. **QUICK_REFERENCE.txt** - Quick reference card
9. **TEST_FILES_SUMMARY.txt** - Complete package summary
10. **INDEX.md** - This file

---

## 🚀 Where to Start?

### If you want to run tests immediately:
```bash
chmod +x test_all.sh
./test_all.sh
```

### If you want to understand what's being tested:
1. Read **README_TESTS.md** first
2. Then read **TESTING_GUIDE.md**
3. For edge cases, check **TRICKY_TESTS.md**

### If you want a quick reference:
Open **QUICK_REFERENCE.txt**

### If you want to test manually:
Open **MANUAL_TEST_COMMANDS.txt** and copy-paste

---

## 📖 File Purposes

| File | Purpose | Usage |
|------|---------|-------|
| test_all.sh | Full automated tests | Run: `./test_all.sh` |
| tricky_tests.sh | Edge case tests | Run: `./tricky_tests.sh` |
| run_tests.py | Python test runner | Run: `python3 run_tests.py` |
| README_TESTS.md | Main docs | Read first |
| TESTING_GUIDE.md | Detailed guide | For understanding |
| TRICKY_TESTS.md | Edge cases | For advanced testing |
| MANUAL_TEST_COMMANDS.txt | Manual tests | Copy-paste |
| QUICK_REFERENCE.txt | Quick ref | Quick lookup |
| TEST_FILES_SUMMARY.txt | Summary | Overview |
| INDEX.md | This file | Navigation |

---

## ✅ Test Coverage Summary

### Exercise 00 (BitcoinExchange): ~30 tests
- Valid inputs
- Date validation (leap years, month limits)
- Value validation (0-1000 range)
- Format validation
- File I/O errors
- Permission tests

### Exercise 01 (RPN): ~25 tests
- Valid expressions
- **Single digit enforcement (0-9 only)**
- Multi-digit rejection
- All operators (+, -, *, /)
- Division by zero
- Stack validation
- Invalid characters

### Exercise 02 (PmergeMe): ~20 tests
- Various sequences
- Sorting correctness
- Input validation
- Performance tests
- Edge cases (duplicates, zeros, INT_MAX)
- Error handling

**Total: ~75 comprehensive test cases**

---

## 🎯 Critical Test Points

### Ex00 Must Test:
- ✓ Leap years: 2000✓ 1900✗ 2020✓ 2021✗
- ✓ Month days: Feb 31✗, Apr 31✗, Jan 31✓
- ✓ Value range: -1✗, 0✓, 1000✓, 1001✗

### Ex01 Must Test:
- ✓ Single digits: 0-9 all work
- ✗ Multi-digit: 10, 99, 123 MUST FAIL
- ✗ Division by zero
- ✗ Stack errors

### Ex02 Must Test:
- ✓ Various sorting scenarios
- ✗ Negative numbers
- ✗ Float numbers
- ✓ Performance with large sets

---

## 🛠️ Quick Commands

```bash
# Run all tests
chmod +x test_all.sh && ./test_all.sh

# Run tricky tests only
chmod +x tricky_tests.sh && ./tricky_tests.sh

# Python tests
python3 run_tests.py

# Memory leak check (Ex00)
cd ex00 && make && valgrind --leak-check=full ./btc test.txt

# Memory leak check (Ex01)
cd ex01 && make && valgrind --leak-check=full ./RPN "1 2 +"

# Memory leak check (Ex02)
cd ex02 && make && valgrind --leak-check=full ./PmergeMe 3 5 9 7 4

# Compile all
cd ex00 && make re && cd ../ex01 && make re && cd ../ex02 && make re && cd ..

# Clean all
cd ex00 && make fclean && cd ../ex01 && make fclean && cd ../ex02 && make fclean && cd ..
```

---

## 📋 Testing Workflow

1. **Compile**: Ensure all exercises compile without warnings
2. **Basic Tests**: Run valid inputs to verify basic functionality
3. **Error Tests**: Test invalid inputs for proper error handling
4. **Edge Cases**: Run tricky tests (permissions, boundaries)
5. **Memory Check**: Run valgrind on all exercises
6. **Performance**: Test Ex02 with large datasets

---

## ⚠️ Important Reminders

1. **Ex01 is STRICT**: Only single digits (0-9) allowed!
2. **Ex00 Date Validation**: Must handle leap years correctly
3. **No Code Changes**: All tests work without modifying implementation
4. **Memory Leaks**: Must pass valgrind with no leaks
5. **Compilation**: Must compile with -Wall -Wextra -Werror -std=c++98

---

## 📞 Getting Help

1. Start with **README_TESTS.md**
2. Check **QUICK_REFERENCE.txt** for quick lookups
3. Read **TESTING_GUIDE.md** for detailed test explanations
4. Check **TRICKY_TESTS.md** for edge case understanding

---

## 🎓 Test Categories

1. **Functional Tests**: Normal operation
2. **Error Tests**: Invalid inputs
3. **Boundary Tests**: Min/max values
4. **Permission Tests**: File access
5. **Edge Cases**: Tricky scenarios
6. **Performance Tests**: Large datasets (Ex02)
7. **Memory Tests**: Leak detection

---

## ✨ Features

- ✅ Comprehensive coverage (~75 tests)
- ✅ No code modifications needed
- ✅ Multiple testing approaches (bash, python, manual)
- ✅ Detailed documentation
- ✅ Permission-based tests
- ✅ Edge case coverage
- ✅ Memory leak testing guidance
- ✅ Quick reference for common tasks

---

## 🎉 Ready to Test!

Start with:
```bash
cat QUICK_REFERENCE.txt    # Quick overview
./test_all.sh              # Run all tests
```

Good luck! 🚀
