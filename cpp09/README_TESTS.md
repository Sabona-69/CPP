# CPP09 Testing Suite

This directory contains comprehensive testing resources for all three exercises in CPP09.

## 📁 Test Files Created

1. **`test_all.sh`** - Automated test script for all exercises
2. **`tricky_tests.sh`** - Permission-based and edge case tests
3. **`run_tests.py`** - Python-based test runner
4. **`TESTING_GUIDE.md`** - Detailed manual testing guide
5. **`TRICKY_TESTS.md`** - Documentation of all tricky edge cases
6. **`MANUAL_TEST_COMMANDS.txt`** - Copy-paste manual test commands
7. **`README_TESTS.md`** - This file

## 🚀 Quick Start

### Option 1: Automated Testing (Bash Script)
```bash
chmod +x test_all.sh
./test_all.sh
```

### Option 2: Tricky Tests Only
```bash
chmod +x tricky_tests.sh
./tricky_tests.sh
```

### Option 3: Python Test Runner
```bash
python3 run_tests.py
```

### Option 4: Manual Testing
Open `MANUAL_TEST_COMMANDS.txt` and copy-paste commands one by one.

## 📋 What Gets Tested

### Exercise 00: BitcoinExchange

#### ✅ Valid Cases
- Valid date and value pairs
- Boundary values (0, 1000)
- Floating point values
- Multiple entries

#### ❌ Error Cases
- Invalid date formats (month > 12, day > 31)
- Invalid dates for specific months (Feb 31, Apr 31, etc.)
- Leap year validation (1900, 2000, 2020, 2021)
- Negative values
- Values over 1000
- Non-numeric values
- Bad delimiters
- Missing file
- No read permissions
- Invalid headers

### Exercise 01: RPN Calculator

**CRITICAL:** Only single digits 0-9 are accepted!

#### ✅ Valid Cases
- Single digits (0-9) with all operators (+, -, *, /)
- Complex expressions: `8 9 * 9 - 9 - 9 - 4 - 1 +` = 42
- Integer division with truncation

#### ❌ Error Cases
- **Multi-digit numbers** (10, 99, 123) - MUST FAIL
- Division by zero
- Not enough operands
- Too many operands
- Invalid operators (%, ^, etc.)
- Invalid characters
- Empty input
- No arguments

### Exercise 02: PmergeMe

#### ✅ Valid Cases
- Simple sequences
- Already sorted sequences
- Reverse sorted sequences
- Single element
- Two elements
- Duplicates
- Large numbers (up to INT_MAX)
- Zero values
- Large datasets (100+ numbers)

#### ❌ Error Cases
- Negative numbers
- Non-numeric input
- Float numbers
- Over INT_MAX
- No arguments

## 🎯 Key Testing Points

### Ex00 Specific
- ✓ Date validation is comprehensive (leap years, month days)
- ✓ Value range checking (0-1000 inclusive)
- ✓ File I/O error handling
- ✓ Database file validation

### Ex01 Specific
- ✓ **ONLY digits 0-9 accepted** (no 10, 99, etc.)
- ✓ All four operators work correctly (+, -, *, /)
- ✓ Division by zero detection
- ✓ Stack state validation
- ✓ Integer division truncation

### Ex02 Specific
- ✓ Sorting correctness for all cases
- ✓ Both vector and deque are used
- ✓ Timing is displayed correctly
- ✓ Handles large datasets efficiently
- ✓ Input validation for positive integers only

## 📊 Test Categories

### 1. Basic Functionality Tests
- Normal valid inputs
- Expected error handling

### 2. Boundary Tests
- Minimum/maximum values
- Edge cases (0, 1, 1000, INT_MAX)

### 3. Error Handling Tests
- Invalid inputs
- Missing files
- Malformed data

### 4. Permission Tests
- No read permissions
- Directory instead of file
- Empty files

### 5. Tricky Edge Cases
- Leap year corner cases (1900, 2000, 2100)
- Month-specific day limits
- Multi-digit rejection for RPN
- Integer overflow
- Division by zero variations

## 🔧 Manual Testing Commands

### Ex00 Quick Tests
```bash
cd ex00
make

# Valid input
cat > test.txt << 'EOF'
date | value
2011-01-03 | 3
EOF
./btc test.txt

# Invalid date (Feb 31)
cat > test.txt << 'EOF'
date | value
2011-02-31 | 1
EOF
./btc test.txt

# Over 1000
cat > test.txt << 'EOF'
date | value
2011-01-03 | 1001
EOF
./btc test.txt
```

### Ex01 Quick Tests
```bash
cd ex01
make

# Valid
./RPN "3 4 +"              # Expected: 7
./RPN "8 9 * 9 - 9 - 9 - 9 - 4 - 1 +"  # Expected: 42

# Invalid (multi-digit)
./RPN "10 2 +"             # Expected: ERROR
./RPN "99 1 +"             # Expected: ERROR

# Division by zero
./RPN "5 0 /"              # Expected: ERROR
```

### Ex02 Quick Tests
```bash
cd ex02
make

# Valid
./PmergeMe 3 5 9 7 4
./PmergeMe 9 8 7 6 5 4 3 2 1

# Invalid
./PmergeMe 1 -2 3          # Negative (ERROR)
./PmergeMe 1 2.5 3         # Float (ERROR)
./PmergeMe                 # No args (ERROR)
```

## 🐛 Debugging

### Memory Leak Testing
```bash
# Ex00
cd ex00 && make
valgrind --leak-check=full --show-leak-kinds=all ./btc test.txt

# Ex01
cd ex01 && make
valgrind --leak-check=full --show-leak-kinds=all ./RPN "1 2 +"

# Ex02
cd ex02 && make
valgrind --leak-check=full --show-leak-kinds=all ./PmergeMe 3 5 9 7 4
```

### Compilation Warnings
All exercises should compile with:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

No warnings or errors should appear during compilation.

## 📝 Expected Behavior

### Ex00
- **Success**: Displays "date => value = result"
- **Errors**: Descriptive error messages starting with "Error:"
- Returns 1 on error, 0 on success

### Ex01
- **Success**: Displays the final result (single number)
- **Errors**: Descriptive error message
- Returns 1 on error, 0 on success

### Ex02
- **Success**: Displays:
  - Before: [original sequence]
  - After: [sorted sequence]
  - Time to process with std::vector: X us
  - Time to process with std::deque: Y us
- **Errors**: Error message starting with "Error:"
- Returns 1 on error, 0 on success

## ⚠️ Important Notes

1. **Ex01 is STRICT**: Only single digits (0-9) are allowed. Multi-digit numbers like 10, 99, or 123 MUST be rejected.

2. **Ex00 Date Validation**: Must correctly handle:
   - Leap years (divisible by 4, except century years unless divisible by 400)
   - Different month lengths (28/29 for Feb, 30 for Apr/Jun/Sep/Nov, 31 for others)

3. **Ex02 Performance**: Should handle large sequences (1000+ elements) efficiently.

4. **No Code Changes**: All tests can be performed without modifying the implementation.

## 🎓 Testing Strategy

1. **Start Simple**: Run basic valid cases first
2. **Test Boundaries**: Check min/max values
3. **Break It**: Try invalid inputs
4. **Get Tricky**: Permission tests, edge cases
5. **Performance**: Large datasets for Ex02
6. **Memory**: Run with valgrind

## 📚 Documentation Files

- **TESTING_GUIDE.md**: Complete manual testing guide with all test cases
- **TRICKY_TESTS.md**: Advanced edge cases and corner cases
- **MANUAL_TEST_COMMANDS.txt**: Ready-to-copy terminal commands

## ✅ Checklist

Before considering testing complete:

- [ ] All valid inputs produce correct output
- [ ] All invalid inputs produce appropriate error messages
- [ ] No memory leaks (valgrind clean)
- [ ] No segmentation faults
- [ ] Handles boundary conditions properly
- [ ] Input validation is strict and correct
- [ ] File I/O errors are handled gracefully
- [ ] Performance is acceptable for large inputs (ex02)
- [ ] Output format matches requirements exactly
- [ ] Programs compile with -Wall -Wextra -Werror -std=c++98

## 🤝 Contributing

To add more tests:
1. Add test cases to the appropriate section in `test_all.sh`
2. Document the test in `TESTING_GUIDE.md`
3. Update this README if adding new test categories

## 📞 Support

If you find any issues or have suggestions:
1. Check the implementation code
2. Verify the test is correct
3. Document any discrepancies

---

**Remember**: The goal is to ensure the implementation is robust, handles all edge cases correctly, and follows the subject requirements precisely!
