#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}Testing CPP09 Exercises${NC}"
echo -e "${BLUE}========================================${NC}"

# ============================================
# EXERCISE 00: BitcoinExchange
# ============================================
echo -e "\n${GREEN}========== EXERCISE 00: BitcoinExchange ==========${NC}\n"

cd ex00
echo -e "${YELLOW}Compiling ex00...${NC}"
make re > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed!${NC}"
    make
    cd ..
    exit 1
fi
echo -e "${GREEN}Compilation successful!${NC}\n"

# Check if data.csv exists
if [ ! -f "data.csv" ]; then
    echo -e "${RED}Error: data.csv not found!${NC}"
    echo -e "${YELLOW}Creating basic data.csv for testing...${NC}"
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
fi

# Create test input file
echo -e "${YELLOW}Test 1: Valid inputs${NC}"
cat > test_input.txt << 'EOF'
date | value
2011-01-03 | 3
2012-01-11 | 2
2013-01-09 | 1
EOF
./btc test_input.txt
echo ""

# Test 2: Invalid date format
echo -e "${YELLOW}Test 2: Invalid date format${NC}"
cat > test_input.txt << 'EOF'
date | value
2011-13-03 | 3
2012-01-32 | 2
2011/01/03 | 1
EOF
./btc test_input.txt
echo ""

# Test 3: Negative value
echo -e "${YELLOW}Test 3: Negative value${NC}"
cat > test_input.txt << 'EOF'
date | value
2011-01-03 | -1
EOF
./btc test_input.txt
echo ""

# Test 4: Too large value
echo -e "${YELLOW}Test 4: Too large value${NC}"
cat > test_input.txt << 'EOF'
date | value
2011-01-03 | 1001
2012-01-11 | 5000
EOF
./btc test_input.txt
echo ""

# Test 5: Invalid format
echo -e "${YELLOW}Test 5: Invalid format (bad delimiter)${NC}"
cat > test_input.txt << 'EOF'
date | value
2011-01-03 3
2012-01-11|2
2013-01-09 - 1
EOF
./btc test_input.txt
echo ""

# Test 6: Empty value
echo -e "${YELLOW}Test 6: Empty value${NC}"
cat > test_input.txt << 'EOF'
date | value
2011-01-03 | 
EOF
./btc test_input.txt
echo ""

# Test 7: Non-numeric value
echo -e "${YELLOW}Test 7: Non-numeric value${NC}"
cat > test_input.txt << 'EOF'
date | value
2011-01-03 | abc
2012-01-11 | 1.2.3
EOF
./btc test_input.txt
echo ""

# Test 8: Missing file
echo -e "${YELLOW}Test 8: Missing file${NC}"
./btc nonexistent.txt 2>&1
echo ""

# Test 9: No arguments
echo -e "${YELLOW}Test 9: No arguments${NC}"
./btc 2>&1
echo ""

# Test 10: Too many arguments
echo -e "${YELLOW}Test 10: Too many arguments${NC}"
./btc test_input.txt extra_arg 2>&1
echo ""

# Test 11: Boundary values
echo -e "${YELLOW}Test 11: Boundary values (0, 1000)${NC}"
cat > test_input.txt << 'EOF'
date | value
2011-01-03 | 0
2012-01-11 | 1000
2013-01-09 | 0.01
EOF
./btc test_input.txt
echo ""

# Test 12: Leap year validation
echo -e "${YELLOW}Test 12: Leap year validation${NC}"
cat > test_input.txt << 'EOF'
date | value
2020-02-29 | 1
2021-02-29 | 1
2000-02-29 | 1
1900-02-29 | 1
EOF
./btc test_input.txt
echo ""

# Cleanup
rm -f test_input.txt

cd ..

# ============================================
# EXERCISE 01: RPN Calculator
# ============================================
echo -e "\n${GREEN}========== EXERCISE 01: RPN Calculator ==========${NC}\n"

cd ex01
echo -e "${YELLOW}Compiling ex01...${NC}"
make re > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed!${NC}"
    make
    cd ..
    exit 1
fi
echo -e "${GREEN}Compilation successful!${NC}\n"

# Test 1: Simple operations
echo -e "${YELLOW}Test 1: Simple operations${NC}"
echo -n "8 9 * 9 - 9 - 9 - 4 - 1 + = "
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo -n "7 7 * 7 - = "
./RPN "7 7 * 7 -"
echo -n "1 2 * 2 / 2 * 2 4 - + = "
./RPN "1 2 * 2 / 2 * 2 4 - +"
echo -n "3 4 + = "
./RPN "3 4 +"
echo ""

# Test 2: Division
echo -e "${YELLOW}Test 2: Division${NC}"
echo -n "9 3 / = "
./RPN "9 3 /"
echo -n "8 2 / 4 / = "
./RPN "8 2 / 4 /"
echo ""

# Test 3: Only digits 0-9 allowed
echo -e "${YELLOW}Test 3: Only single digits 0-9 allowed${NC}"
echo -n "0 1 + = "
./RPN "0 1 +"
echo -n "9 9 + = "
./RPN "9 9 +"
echo ""

# Test 4: Invalid - multi-digit numbers should fail
echo -e "${YELLOW}Test 4: Multi-digit numbers (should fail)${NC}"
echo -n "10 2 + = "
./RPN "10 2 +" 2>&1
echo -n "99 1 + = "
./RPN "99 1 +" 2>&1
echo ""

# Test 5: Invalid operators
echo -e "${YELLOW}Test 5: Invalid operators${NC}"
echo -n "1 2 % = "
./RPN "1 2 %" 2>&1
echo -n "1 2 ^ = "
./RPN "1 2 ^" 2>&1
echo -n "1 2 a = "
./RPN "1 2 a" 2>&1
echo ""

# Test 6: Division by zero
echo -e "${YELLOW}Test 6: Division by zero${NC}"
echo -n "5 0 / = "
./RPN "5 0 /" 2>&1
echo ""

# Test 7: Not enough operands
echo -e "${YELLOW}Test 7: Not enough operands${NC}"
echo -n "1 + = "
./RPN "1 +" 2>&1
echo -n "+ = "
./RPN "+" 2>&1
echo ""

# Test 8: Too many operands
echo -e "${YELLOW}Test 8: Too many operands${NC}"
echo -n "1 2 3 + = "
./RPN "1 2 3 +" 2>&1
echo ""

# Test 9: Empty input
echo -e "${YELLOW}Test 9: Empty input${NC}"
./RPN "" 2>&1
echo ""

# Test 10: No arguments
echo -e "${YELLOW}Test 10: No arguments${NC}"
./RPN 2>&1
echo ""

# Test 11: Multiple arguments
echo -e "${YELLOW}Test 11: Multiple arguments${NC}"
./RPN "1 2 +" "3 4 +" 2>&1
echo ""

# Test 12: Invalid characters
echo -e "${YELLOW}Test 12: Invalid characters${NC}"
echo -n "1 2 + abc = "
./RPN "1 2 + abc" 2>&1
echo -n "a b + = "
./RPN "a b +" 2>&1
echo ""

# Test 13: All operators
echo -e "${YELLOW}Test 13: All operators${NC}"
echo -n "5 3 + = "
./RPN "5 3 +"
echo -n "5 3 - = "
./RPN "5 3 -"
echo -n "5 3 * = "
./RPN "5 3 *"
echo -n "6 3 / = "
./RPN "6 3 /"
echo ""

cd ..

# ============================================
# EXERCISE 02: PmergeMe
# ============================================
echo -e "\n${GREEN}========== EXERCISE 02: PmergeMe ==========${NC}\n"

cd ex02
echo -e "${YELLOW}Compiling ex02...${NC}"
make re > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed!${NC}"
    make
    cd ..
    exit 1
fi
echo -e "${GREEN}Compilation successful!${NC}\n"

# Test 1: Simple sequence
echo -e "${YELLOW}Test 1: Simple sequence${NC}"
./PmergeMe 3 5 9 7 4
echo ""

# Test 2: Already sorted
echo -e "${YELLOW}Test 2: Already sorted${NC}"
./PmergeMe 1 2 3 4 5
echo ""

# Test 3: Reverse sorted
echo -e "${YELLOW}Test 3: Reverse sorted${NC}"
./PmergeMe 9 8 7 6 5 4 3 2 1
echo ""

# Test 4: Single element
echo -e "${YELLOW}Test 4: Single element${NC}"
./PmergeMe 42
echo ""

# Test 5: Two elements
echo -e "${YELLOW}Test 5: Two elements${NC}"
./PmergeMe 2 1
echo ""

# Test 6: Duplicates
echo -e "${YELLOW}Test 6: Duplicates${NC}"
./PmergeMe 5 5 5 5 5
echo ""

# Test 7: Large numbers
echo -e "${YELLOW}Test 7: Large positive numbers${NC}"
./PmergeMe 2147483647 1 999999999 42
echo ""

# Test 8: Larger sequence
echo -e "${YELLOW}Test 8: Larger sequence (20 numbers)${NC}"
./PmergeMe 15 8 23 4 16 42 11 9 27 3 19 7 31 2 13 5 29 1 17 21
echo ""

# Test 9: No arguments
echo -e "${YELLOW}Test 9: No arguments${NC}"
./PmergeMe 2>&1
echo ""

# Test 10: Negative numbers
echo -e "${YELLOW}Test 10: Negative numbers (should fail)${NC}"
./PmergeMe 1 -2 3 2>&1
echo ""

# Test 11: Non-numeric input
echo -e "${YELLOW}Test 11: Non-numeric input${NC}"
./PmergeMe 1 abc 3 2>&1
echo ""

# Test 12: Float numbers
echo -e "${YELLOW}Test 12: Float numbers (should fail)${NC}"
./PmergeMe 1 2.5 3 2>&1
echo ""

# Test 13: Very large sequence (performance test)
echo -e "${YELLOW}Test 13: Large sequence (100 numbers - performance)${NC}"
./PmergeMe $(seq 100 -1 1 | tr '\n' ' ')
echo ""

# Test 14: Zero
echo -e "${YELLOW}Test 14: Including zero${NC}"
./PmergeMe 0 5 3 8 1
echo ""

cd ..

echo -e "\n${BLUE}========================================${NC}"
echo -e "${BLUE}All tests completed!${NC}"
echo -e "${BLUE}========================================${NC}"
