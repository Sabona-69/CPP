#!/bin/bash

# Permission-Based and Tricky Tests for CPP09
# These tests don't modify code, just test edge cases

set -e

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo -e "${BLUE}╔══════════════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║     CPP09 Permission & Tricky Tests                  ║${NC}"
echo -e "${BLUE}╚══════════════════════════════════════════════════════╝${NC}"

# ========================================
# EX00 Permission Tests
# ========================================
echo -e "\n${GREEN}=== Exercise 00: Permission Tests ===${NC}\n"

cd ex00
make re > /dev/null 2>&1

# Create a test input file
cat > test_input.txt << 'EOF'
date | value
2011-01-03 | 3
EOF

# Test 1: No read permission on data.csv
echo -e "${YELLOW}Test: Remove read permission from data.csv${NC}"
if [ -f data.csv ]; then
    chmod 000 data.csv
    ./btc test_input.txt 2>&1 | head -3
    chmod 644 data.csv
else
    echo "data.csv not found, skipping test"
fi
echo ""

# Test 2: No read permission on input file
echo -e "${YELLOW}Test: Remove read permission from input file${NC}"
chmod 000 test_input.txt
./btc test_input.txt 2>&1 | head -3
chmod 644 test_input.txt
echo ""

# Test 3: Directory instead of file
echo -e "${YELLOW}Test: Pass directory instead of file${NC}"
mkdir -p test_dir
./btc test_dir 2>&1 | head -3
rmdir test_dir
echo ""

# Test 4: Empty file
echo -e "${YELLOW}Test: Empty input file${NC}"
touch empty.txt
./btc empty.txt 2>&1 | head -3
rm empty.txt
echo ""

# Test 5: File with only header
echo -e "${YELLOW}Test: File with only header${NC}"
cat > header_only.txt << 'EOF'
date | value
EOF
./btc header_only.txt 2>&1
rm header_only.txt
echo ""

# Test 6: Invalid header
echo -e "${YELLOW}Test: Invalid header${NC}"
cat > bad_header.txt << 'EOF'
wrong header
2011-01-03 | 3
EOF
./btc bad_header.txt 2>&1 | head -3
rm bad_header.txt
echo ""

# Test 7: Months with different day counts
echo -e "${YELLOW}Test: Invalid day for specific months${NC}"
cat > month_days.txt << 'EOF'
date | value
2011-02-31 | 1
2011-04-31 | 1
2011-06-31 | 1
2011-09-31 | 1
2011-11-31 | 1
EOF
./btc month_days.txt 2>&1
rm month_days.txt
echo ""

# Test 8: Comprehensive leap year test
echo -e "${YELLOW}Test: Leap year edge cases${NC}"
cat > leap_year.txt << 'EOF'
date | value
2000-02-29 | 1
1900-02-29 | 1
2004-02-29 | 1
2100-02-29 | 1
2020-02-29 | 1
2021-02-29 | 1
EOF
./btc leap_year.txt 2>&1
rm leap_year.txt
echo ""

# Test 9: Very small and very large values
echo -e "${YELLOW}Test: Boundary value testing${NC}"
cat > boundaries.txt << 'EOF'
date | value
2011-01-03 | 0
2011-01-03 | 0.000001
2011-01-03 | 999.999999
2011-01-03 | 1000
2011-01-03 | 1000.000001
EOF
./btc boundaries.txt 2>&1
rm boundaries.txt
echo ""

# Test 10: Multiple delimiter issues
echo -e "${YELLOW}Test: Delimiter variations${NC}"
cat > delimiters.txt << 'EOF'
date | value
2011-01-03| 3
2011-01-03 |3
2011-01-03  |  3
2011-01-03 || 3
EOF
./btc delimiters.txt 2>&1
rm delimiters.txt
echo ""

rm -f test_input.txt
cd ..

# ========================================
# EX01 Strict Digit Tests
# ========================================
echo -e "\n${GREEN}=== Exercise 01: Strict Single-Digit Tests ===${NC}\n"

cd ex01
make re > /dev/null 2>&1

# Test 1: Multi-digit numbers (MUST FAIL)
echo -e "${YELLOW}Test: Multi-digit numbers (should all fail)${NC}"
./RPN "10 2 +" 2>&1 | head -1
./RPN "12 34 +" 2>&1 | head -1
./RPN "100 200 +" 2>&1 | head -1
echo ""

# Test 2: All single digits should work
echo -e "${YELLOW}Test: All single digits (0-9)${NC}"
for i in {0..9}; do
    result=$(./RPN "$i 0 +" 2>&1 | head -1)
    echo "  $i + 0 = $result"
done
echo ""

# Test 3: No spaces (should fail)
echo -e "${YELLOW}Test: No spaces between tokens${NC}"
./RPN "12+" 2>&1 | head -1
./RPN "1 2+" 2>&1 | head -1
echo ""

# Test 4: Integer division
echo -e "${YELLOW}Test: Integer division (truncation)${NC}"
./RPN "5 2 /" 2>&1 | head -1
echo "  Expected: 2 (not 2.5)"
./RPN "7 3 /" 2>&1 | head -1
echo "  Expected: 2 (not 2.333...)"
./RPN "1 2 /" 2>&1 | head -1
echo "  Expected: 0 (not 0.5)"
echo ""

# Test 5: Division by zero variations
echo -e "${YELLOW}Test: Division by zero${NC}"
./RPN "0 0 /" 2>&1 | head -1
./RPN "5 0 /" 2>&1 | head -1
./RPN "9 9 - 1 /" 2>&1 | head -1  # Results in 1/0
echo ""

# Test 6: Stack underflow
echo -e "${YELLOW}Test: Stack underflow${NC}"
./RPN "+" 2>&1 | head -1
./RPN "1 +" 2>&1 | head -1
./RPN "1 2 + +" 2>&1 | head -1
echo ""

# Test 7: Stack overflow (multiple values remaining)
echo -e "${YELLOW}Test: Too many values remaining${NC}"
./RPN "1 2" 2>&1 | head -1
./RPN "1 2 3 +" 2>&1 | head -1
./RPN "1 2 3 4 +" 2>&1 | head -1
echo ""

# Test 8: Invalid characters
echo -e "${YELLOW}Test: Invalid characters${NC}"
./RPN "a b +" 2>&1 | head -1
./RPN "1 2 %" 2>&1 | head -1
./RPN "1 2 ^" 2>&1 | head -1
./RPN "1 2 &" 2>&1 | head -1
echo ""

# Test 9: Complex valid expressions
echo -e "${YELLOW}Test: Complex valid expressions${NC}"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" 2>&1 | head -1
echo "  Expected: 42"
./RPN "7 7 * 7 -" 2>&1 | head -1
echo "  Expected: 42"
echo ""

cd ..

# ========================================
# EX02 Edge Cases
# ========================================
echo -e "\n${GREEN}=== Exercise 02: Edge Case Tests ===${NC}\n"

cd ex02
make re > /dev/null 2>&1

# Test 1: Single element
echo -e "${YELLOW}Test: Single element${NC}"
./PmergeMe 42 2>&1 | grep -E "(Before|After)"
echo ""

# Test 2: Two elements (min for sorting)
echo -e "${YELLOW}Test: Two elements${NC}"
./PmergeMe 5 2 2>&1 | grep -E "(Before|After)"
echo ""

# Test 3: All same values
echo -e "${YELLOW}Test: All identical values${NC}"
./PmergeMe 7 7 7 7 7 7 7 2>&1 | grep -E "(Before|After)"
echo ""

# Test 4: Already sorted
echo -e "${YELLOW}Test: Already sorted${NC}"
./PmergeMe 1 2 3 4 5 6 7 8 9 2>&1 | grep -E "(Before|After)"
echo ""

# Test 5: Reverse sorted
echo -e "${YELLOW}Test: Reverse sorted${NC}"
./PmergeMe 9 8 7 6 5 4 3 2 1 2>&1 | grep -E "(Before|After)"
echo ""

# Test 6: With zeros
echo -e "${YELLOW}Test: Including zeros${NC}"
./PmergeMe 0 5 3 0 8 1 0 2>&1 | grep -E "(Before|After)"
echo ""

# Test 7: Large numbers
echo -e "${YELLOW}Test: Large numbers (near INT_MAX)${NC}"
./PmergeMe 2147483647 2147483646 1 0 2>&1 | grep -E "(Before|After)"
echo ""

# Test 8: Negative numbers (should fail)
echo -e "${YELLOW}Test: Negative numbers (should fail)${NC}"
./PmergeMe 1 -2 3 2>&1 | head -1
echo ""

# Test 9: Non-numeric (should fail)
echo -e "${YELLOW}Test: Non-numeric input (should fail)${NC}"
./PmergeMe 1 abc 3 2>&1 | head -1
./PmergeMe 1 2.5 3 2>&1 | head -1
echo ""

# Test 10: Over INT_MAX (should fail)
echo -e "${YELLOW}Test: Over INT_MAX (should fail)${NC}"
./PmergeMe 2147483648 2>&1 | head -1
echo ""

# Test 11: Empty argument
echo -e "${YELLOW}Test: Empty argument${NC}"
./PmergeMe "" 2>&1 | head -1
echo ""

# Test 12: No arguments
echo -e "${YELLOW}Test: No arguments${NC}"
./PmergeMe 2>&1 | head -1
echo ""

cd ..

echo -e "\n${BLUE}╔══════════════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║     All Permission & Tricky Tests Complete!         ║${NC}"
echo -e "${BLUE}╚══════════════════════════════════════════════════════╝${NC}"

echo -e "\n${YELLOW}Optional: Run with valgrind to check for memory leaks${NC}"
echo "  cd ex00 && valgrind --leak-check=full ./btc test_input.txt"
echo "  cd ex01 && valgrind --leak-check=full ./RPN '1 2 +'"
echo "  cd ex02 && valgrind --leak-check=full ./PmergeMe 3 5 9 7 4"
