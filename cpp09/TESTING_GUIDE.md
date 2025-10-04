# CPP09 Testing Guide

This guide provides comprehensive testing instructions for all three exercises in cpp09.

## Exercise 00: BitcoinExchange

### Compilation
```bash
cd ex00
make
```

### Test Files Setup

First, ensure you have a `data.csv` file. If not, create one:
```bash
cat > data.csv << 'EOF'
date,exchange_rate
2009-01-02,0
2011-01-03,0.3
2012-01-11,3
2013-01-09,13
2014-01-03,36
2015-01-01,183
2016-01-01,434
2017-01-01,997
2018-01-01,13850
2019-01-01,3844
2020-01-01,7348
2021-01-01,29374
2022-01-01,46306
2023-01-01,16547
EOF
```

### Test Cases

#### Test 1: Valid Inputs
```bash
cat > test_input.txt << 'EOF'
date | value
2011-01-03 | 3
2012-01-11 | 2
2013-01-09 | 1
EOF
./btc test_input.txt
```
**Expected:** Should display calculated values based on exchange rates

#### Test 2: Invalid Date Format
```bash
cat > test_input.txt << 'EOF'
date | value
2011-13-03 | 3
2012-01-32 | 2
2011/01/03 | 1
EOF
./btc test_input.txt
```
**Expected:** Error messages for bad input

#### Test 3: Negative Value
```bash
cat > test_input.txt << 'EOF'
date | value
2011-01-03 | -1
EOF
./btc test_input.txt
```
**Expected:** "Error: not a positive number."

#### Test 4: Too Large Value
```bash
cat > test_input.txt << 'EOF'
date | value
2011-01-03 | 1001
2012-01-11 | 5000
EOF
./btc test_input.txt
```
**Expected:** "Error: too large a number."

#### Test 5: Invalid Format (Bad Delimiter)
```bash
cat > test_input.txt << 'EOF'
date | value
2011-01-03 3
2012-01-11|2
2013-01-09 - 1
EOF
./btc test_input.txt
```
**Expected:** "Error: bad input => ..."

#### Test 6: Empty Value
```bash
cat > test_input.txt << 'EOF'
date | value
2011-01-03 | 
EOF
./btc test_input.txt
```
**Expected:** "Error: bad input => ..."

#### Test 7: Non-Numeric Value
```bash
cat > test_input.txt << 'EOF'
date | value
2011-01-03 | abc
2012-01-11 | 1.2.3
EOF
./btc test_input.txt
```
**Expected:** "Error: bad input => ..."

#### Test 8: Missing File
```bash
./btc nonexistent.txt
```
**Expected:** "Error: could not open file."

#### Test 9: No Arguments
```bash
./btc
```
**Expected:** "Error: could not open file."

#### Test 10: Too Many Arguments
```bash
./btc test_input.txt extra_arg
```
**Expected:** "Error: could not open file."

#### Test 11: Boundary Values (0, 1000)
```bash
cat > test_input.txt << 'EOF'
date | value
2011-01-03 | 0
2012-01-11 | 1000
2013-01-09 | 0.01
EOF
./btc test_input.txt
```
**Expected:** All values should be accepted and calculated

#### Test 12: Leap Year Validation
```bash
cat > test_input.txt << 'EOF'
date | value
2020-02-29 | 1
2021-02-29 | 1
2000-02-29 | 1
1900-02-29 | 1
EOF
./btc test_input.txt
```
**Expected:** 
- 2020-02-29: Valid (leap year)
- 2021-02-29: Invalid (not a leap year)
- 2000-02-29: Valid (divisible by 400)
- 1900-02-29: Invalid (not a leap year)

---

## Exercise 01: RPN Calculator

**IMPORTANT:** This exercise only accepts single digits 0-9. Multi-digit numbers should fail.

### Compilation
```bash
cd ex01
make
```

### Test Cases

#### Test 1: Simple Operations
```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"  # Expected: 42
./RPN "7 7 * 7 -"                   # Expected: 42
./RPN "1 2 * 2 / 2 * 2 4 - +"       # Expected: 0
./RPN "3 4 +"                       # Expected: 7
```

#### Test 2: Division
```bash
./RPN "9 3 /"        # Expected: 3
./RPN "8 2 / 4 /"    # Expected: 1
```

#### Test 3: Only Digits 0-9 Allowed
```bash
./RPN "0 1 +"    # Expected: 1
./RPN "9 9 +"    # Expected: 18
```

#### Test 4: Multi-Digit Numbers (Should FAIL)
```bash
./RPN "10 2 +"   # Expected: Error (multi-digit not allowed)
./RPN "99 1 +"   # Expected: Error (multi-digit not allowed)
```

#### Test 5: Invalid Operators
```bash
./RPN "1 2 %"    # Expected: Error
./RPN "1 2 ^"    # Expected: Error
./RPN "1 2 a"    # Expected: Error
```

#### Test 6: Division by Zero
```bash
./RPN "5 0 /"    # Expected: Error: Division by zero
```

#### Test 7: Not Enough Operands
```bash
./RPN "1 +"      # Expected: Error
./RPN "+"        # Expected: Error
```

#### Test 8: Too Many Operands
```bash
./RPN "1 2 3 +"  # Expected: Error (should have exactly one value left)
```

#### Test 9: Empty Input
```bash
./RPN ""         # Expected: Error
```

#### Test 10: No Arguments
```bash
./RPN            # Expected: Error
```

#### Test 11: Multiple Arguments
```bash
./RPN "1 2 +" "3 4 +"  # Expected: Error
```

#### Test 12: Invalid Characters
```bash
./RPN "1 2 + abc"    # Expected: Error
./RPN "a b +"        # Expected: Error
```

#### Test 13: All Operators
```bash
./RPN "5 3 +"    # Expected: 8
./RPN "5 3 -"    # Expected: 2
./RPN "5 3 *"    # Expected: 15
./RPN "6 3 /"    # Expected: 2
```

---

## Exercise 02: PmergeMe

### Compilation
```bash
cd ex02
make
```

### Test Cases

#### Test 1: Simple Sequence
```bash
./PmergeMe 3 5 9 7 4
```
**Expected:** Should display Before, After (sorted), and timing for vector and deque

#### Test 2: Already Sorted
```bash
./PmergeMe 1 2 3 4 5
```
**Expected:** After should be same as Before

#### Test 3: Reverse Sorted
```bash
./PmergeMe 9 8 7 6 5 4 3 2 1
```
**Expected:** After should be 1 2 3 4 5 6 7 8 9

#### Test 4: Single Element
```bash
./PmergeMe 42
```
**Expected:** Before and After should both be 42

#### Test 5: Two Elements
```bash
./PmergeMe 2 1
```
**Expected:** After should be 1 2

#### Test 6: Duplicates
```bash
./PmergeMe 5 5 5 5 5
```
**Expected:** After should be 5 5 5 5 5

#### Test 7: Large Positive Numbers
```bash
./PmergeMe 2147483647 1 999999999 42
```
**Expected:** Should handle large integers correctly

#### Test 8: Larger Sequence (20 Numbers)
```bash
./PmergeMe 15 8 23 4 16 42 11 9 27 3 19 7 31 2 13 5 29 1 17 21
```
**Expected:** Should sort correctly and show timing

#### Test 9: No Arguments
```bash
./PmergeMe
```
**Expected:** Error: Not enough arguments

#### Test 10: Negative Numbers (Should Fail)
```bash
./PmergeMe 1 -2 3
```
**Expected:** Error (only positive integers allowed)

#### Test 11: Non-Numeric Input
```bash
./PmergeMe 1 abc 3
```
**Expected:** Error

#### Test 12: Float Numbers (Should Fail)
```bash
./PmergeMe 1 2.5 3
```
**Expected:** Error

#### Test 13: Large Sequence (Performance Test)
```bash
./PmergeMe $(seq 100 -1 1 | tr '\n' ' ')
```
**Expected:** Should handle 100 numbers and show timing difference

#### Test 14: Including Zero
```bash
./PmergeMe 0 5 3 8 1
```
**Expected:** Should sort correctly with 0 included

#### Test 15: Very Large Sequence (1000 numbers)
```bash
./PmergeMe $(shuf -i 1-1000 -n 1000 | tr '\n' ' ')
```
**Expected:** Should demonstrate performance with large dataset

---

## Advanced Tests

### Ex00: Tricky Edge Cases

#### Test with Date Before Database Range
```bash
cat > test_input.txt << 'EOF'
date | value
2000-01-01 | 1
EOF
./btc test_input.txt
```
**Expected:** "Error: date is out of range."

#### Test with Whitespace Variations
```bash
cat > test_input.txt << 'EOF'
date | value
  2011-01-03   |   3  
	2012-01-11	|	2	
EOF
./btc test_input.txt
```
**Expected:** Should handle whitespace correctly

#### Test with Invalid Header
```bash
cat > test_input.txt << 'EOF'
wrong header
2011-01-03 | 3
EOF
./btc test_input.txt
```
**Expected:** Error about invalid header

### Ex01: Tricky Edge Cases

#### Test with Extra Spaces
```bash
./RPN "1  2  +"      # Multiple spaces
./RPN " 1 2 + "      # Leading/trailing spaces
```

#### Test with Tab Characters
```bash
./RPN "1	2	+"    # Tabs instead of spaces
```

#### Test Integer Overflow
```bash
./RPN "9 9 * 9 * 9 *"  # Should check for overflow
```

### Ex02: Tricky Edge Cases

#### Test with INT_MAX
```bash
./PmergeMe 2147483647 2147483646 1
```

#### Test with Many Duplicates
```bash
./PmergeMe 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 3 3 3 3
```

#### Test Empty After Program Name
```bash
./PmergeMe ""
```

---

## Cleanup
After testing, clean up temporary files:
```bash
cd ex00 && rm -f test_input.txt && make fclean
cd ../ex01 && make fclean
cd ../ex02 && make fclean
```

---

## Notes

1. **Ex01 Specific:** Only single digits (0-9) are allowed. Any multi-digit number should cause an error.
2. **Ex00:** Requires proper `data.csv` file with correct format.
3. **Ex02:** Should work with both vector and deque, showing timing comparisons.
4. All programs should compile with `-Wall -Wextra -Werror -std=c++98`
5. No memory leaks should occur (can be tested with valgrind if needed)

## Quick Test Commands

Run all basic tests quickly:
```bash
# Ex00
cd ex00 && make && echo "2011-01-03 | 3" | ./btc /dev/stdin 2>&1; cd ..

# Ex01
cd ex01 && make && ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" && cd ..

# Ex02
cd ex02 && make && ./PmergeMe 3 5 9 7 4 && cd ..
```
