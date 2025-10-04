# CPP09 TRICKY TEST CASES - Summary

## Exercise 00: BitcoinExchange - Advanced Edge Cases

### 1. **Permission-Based Tests** (Can be done without code changes)

#### Remove read permission from data.csv
```bash
cd ex00
chmod 000 data.csv
./btc test_input.txt  # Should fail to open database
chmod 644 data.csv  # Restore
```

#### Remove read permission from input file
```bash
chmod 000 test_input.txt
./btc test_input.txt  # Should fail to open file
chmod 644 test_input.txt  # Restore
```

#### Create input file but make it empty
```bash
touch empty.txt
./btc empty.txt  # Should handle empty file
```

### 2. **Date Edge Cases**

#### Months with 30 vs 31 days
```
date | value
2011-02-31 | 1   # Invalid: February has max 29 days
2011-04-31 | 1   # Invalid: April has 30 days
2011-11-31 | 1   # Invalid: November has 30 days
2011-01-31 | 1   # Valid: January has 31 days
```

#### Leap year corner cases
```
date | value
2000-02-29 | 1   # Valid: divisible by 400
1900-02-29 | 1   # Invalid: divisible by 100 but not 400
2004-02-29 | 1   # Valid: divisible by 4
2001-02-29 | 1   # Invalid: not divisible by 4
```

#### Year 0 or negative years
```
date | value
0000-01-01 | 1   # Invalid: year 0
-001-01-01 | 1   # Invalid: negative year
```

### 3. **Value Edge Cases**

#### Floating point precision
```
date | value
2011-01-03 | 0.0000001    # Very small positive
2011-01-03 | 999.999999   # Just under 1000
2011-01-03 | 1000.000001  # Just over 1000
```

#### Scientific notation
```
date | value
2011-01-03 | 1e2    # Should it accept scientific notation?
2011-01-03 | 1.5e3  # Over 1000 in scientific
```

### 4. **Format Edge Cases**

#### Whitespace variations
```
date | value
2011-01-03| 3          # No space before pipe
2011-01-03 |3          # No space after pipe
2011-01-03  |  3       # Multiple spaces
	2011-01-03 | 3         # Tab character
```

#### Extra delimiters
```
date | value
2011-01-03 | 3 | 4     # Multiple pipes
2011-01-03 || 3        # Double pipe
```

#### Line endings
```
# Test with Windows line endings (CRLR)
# Test with Mac line endings (CR)
# Test with Unix line endings (LF)
```

### 5. **Database Edge Cases**

#### Corrupt database header
```bash
# Temporarily modify data.csv header
# Change "date,exchange_rate" to something else
```

#### Database with invalid dates
```bash
# Add line: 2011-13-32,100  # Should fail validation
```

#### Database with negative exchange rates
```bash
# Add line: 2011-01-03,-5  # Should it accept negative rates?
```

### 6. **Date Range Tests**

#### Date before database start
```
date | value
2000-01-01 | 1   # Before 2009-01-02
```

#### Date after database end
```
date | value
2025-01-01 | 1   # After 2023-01-01
```

---

## Exercise 01: RPN - Advanced Edge Cases

### 1. **Strict Single-Digit Enforcement**

#### Multi-digit numbers (MUST FAIL)
```bash
./RPN "10 2 +"        # Two digits together
./RPN "123 456 +"     # Multiple digits
./RPN "1 10 +"        # Mixed single and multi
./RPN "01 2 +"        # Leading zero (is this single digit?)
```

### 2. **Whitespace Handling**

#### Multiple spaces
```bash
./RPN "1  2  +"       # Double spaces
./RPN "1   2   +"     # Triple spaces
```

#### Leading/trailing spaces
```bash
./RPN " 1 2 + "       # Spaces at start/end
./RPN "  1 2 +  "     # Multiple spaces at edges
```

#### Tabs and other whitespace
```bash
./RPN "1	2	+"        # Tabs instead of spaces
./RPN "1\n2\n+"       # Newlines (should fail)
```

#### No spaces (SHOULD FAIL)
```bash
./RPN "12+"           # No spaces between tokens
./RPN "1 2+"          # Missing space before operator
```

### 3. **Operator Edge Cases**

#### Consecutive operators
```bash
./RPN "1 2 + +"       # Not enough operands for second +
./RPN "1 2 + - "      # Not enough operands for -
```

#### Operators at wrong positions
```bash
./RPN "+ 1 2"         # Operator first
./RPN "1 + 2"         # Infix notation (should fail)
```

### 4. **Integer Overflow**

#### Operations that exceed INT_MAX
```bash
./RPN "9 9 * 9 * 9 * 9 * 9 *"   # 9^6 = 531441
./RPN "9 9 + 9 9 + * 9 9 + *"   # Should check for overflow
```

#### Operations below INT_MIN
```bash
./RPN "0 9 -"                    # -9
./RPN "0 9 - 9 - 9 - 9 -"        # Large negative
```

### 5. **Division Edge Cases**

#### Division by zero variants
```bash
./RPN "0 0 /"         # 0 / 0
./RPN "5 0 /"         # Non-zero / 0
./RPN "1 2 - 1 /"     # Result becomes 0, then divide
```

#### Integer division truncation
```bash
./RPN "5 2 /"         # 5 / 2 = 2 (not 2.5)
./RPN "7 3 /"         # 7 / 3 = 2 (not 2.333...)
```

### 6. **Stack State Validation**

#### Empty stack at end
```bash
./RPN "1 2 + 3 -"     # Valid, should leave 0
./RPN "1 2 + 3 - 5 *" # Valid, should leave 0
```

#### Multiple values remaining
```bash
./RPN "1 2 3 4 +"     # Should have 1 2 7 on stack (error)
./RPN "1 2"           # Two values, no operation (error)
```

---

## Exercise 02: PmergeMe - Advanced Edge Cases

### 1. **Input Validation**

#### Numbers with leading zeros
```bash
./PmergeMe 01 02 03      # Should these be treated as valid?
./PmergeMe 001 002 003   # Leading zeros
```

#### Numbers with + sign
```bash
./PmergeMe +1 +2 +3      # Positive sign explicit
./PmergeMe 1 +2 3        # Mixed
```

#### Whitespace in arguments
```bash
./PmergeMe "1 2" 3       # Space in argument
./PmergeMe "1" "" "2"    # Empty argument
```

### 2. **Integer Limits**

#### INT_MAX boundary
```bash
./PmergeMe 2147483647 2147483646 1 0     # Max int
./PmergeMe 2147483648                    # Just over INT_MAX (should fail)
```

#### Zero handling
```bash
./PmergeMe 0              # Single zero
./PmergeMe 0 0 0 0        # Multiple zeros
./PmergeMe 0 1 2          # Zero with others
```

### 3. **Sorting Validation**

#### Already sorted sequences
```bash
./PmergeMe 1 2 3 4 5 6 7 8 9 10              # Ascending
./PmergeMe $(seq 1 100)                       # Large ascending
```

#### Reverse sorted sequences
```bash
./PmergeMe 10 9 8 7 6 5 4 3 2 1              # Descending
./PmergeMe $(seq 100 -1 1)                    # Large descending
```

#### All same values
```bash
./PmergeMe 42 42 42 42 42 42                 # All identical
./PmergeMe $(yes 7 | head -50 | tr '\n' ' ') # 50 identical
```

### 4. **Performance Tests**

#### Small sequences (2-10 elements)
```bash
./PmergeMe 5 2                    # Minimum for comparison
./PmergeMe 5 2 8 1 9 3 7 4 6      # Small odd
./PmergeMe 5 2 8 1 9 3 7 4 6 0    # Small even
```

#### Medium sequences (100-500 elements)
```bash
./PmergeMe $(shuf -i 1-100 -n 100 | tr '\n' ' ')
./PmergeMe $(shuf -i 1-500 -n 500 | tr '\n' ' ')
```

#### Large sequences (1000+ elements)
```bash
./PmergeMe $(shuf -i 1-1000 -n 1000 | tr '\n' ' ')
./PmergeMe $(shuf -i 1-3000 -n 3000 | tr '\n' ' ')
```

### 5. **Output Validation**

#### Before and After comparison
After each test, verify that:
- Before contains all original numbers
- After contains all numbers sorted
- No numbers are lost or duplicated (unless duplicates in input)

#### Timing comparison
- Vector time should be reported
- Deque time should be reported
- Both should process same number of elements

### 6. **Special Patterns**

#### Sawtooth pattern
```bash
./PmergeMe 1 5 2 6 3 7 4 8        # Alternating low-high
```

#### Mountain pattern
```bash
./PmergeMe 1 2 3 4 5 4 3 2 1      # Ascending then descending
```

#### Random with duplicates
```bash
./PmergeMe 3 1 4 1 5 9 2 6 5 3 5  # π digits with duplicates
```

---

## Additional Tricky Tests (All Exercises)

### 1. **Symbolic Links**
```bash
# For ex00
ln -s test_input.txt symlink_input.txt
./btc symlink_input.txt
rm symlink_input.txt
```

### 2. **Named Pipes (FIFO)**
```bash
# For ex00
mkfifo input_pipe
echo "date | value" > input_pipe &
echo "2011-01-03 | 3" >> input_pipe &
./btc input_pipe
rm input_pipe
```

### 3. **Very Large Files**
```bash
# For ex00 - create file with 10000+ lines
for i in {1..10000}; do
    echo "2011-01-03 | 1" >> large_input.txt
done
./btc large_input.txt
rm large_input.txt
```

### 4. **Signal Interruption**
```bash
# Test CTRL+C handling during execution
./PmergeMe $(seq 1 10000) &
# Press CTRL+C
```

### 5. **Memory Stress**
```bash
# Run valgrind on all exercises
cd ex00 && valgrind --leak-check=full ./btc test_input.txt
cd ex01 && valgrind --leak-check=full ./RPN "1 2 +"
cd ex02 && valgrind --leak-check=full ./PmergeMe 3 5 9 7 4
```

---

## Quick Test Runner Script

Save as `quick_tests.sh`:
```bash
#!/bin/bash

echo "=== Quick Tricky Tests ==="

# Ex00 - Remove permissions test
cd ex00
chmod 000 data.csv 2>/dev/null
echo "Test: No read permission on data.csv"
./btc test_input.txt 2>&1 | head -1
chmod 644 data.csv 2>/dev/null
cd ..

# Ex01 - Multi-digit rejection
cd ex01
echo "Test: Multi-digit number (should fail)"
./RPN "10 2 +" 2>&1 | head -1
cd ..

# Ex02 - Negative number rejection
cd ex02
echo "Test: Negative number (should fail)"
./PmergeMe 1 -2 3 2>&1 | head -1
cd ..

echo "=== Tests Complete ==="
```

---

## Checklist

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
