#!/usr/bin/env python3
"""
Comprehensive test suite for CPP09 exercises
"""
import subprocess
import os
import sys

# Color codes
RED = '\033[0;31m'
GREEN = '\033[0;32m'
BLUE = '\033[0;34m'
YELLOW = '\033[1;33m'
NC = '\033[0m'  # No Color

def run_command(cmd, input_text=None, cwd=None):
    """Run a shell command and return output"""
    try:
        result = subprocess.run(
            cmd,
            shell=True,
            capture_output=True,
            text=True,
            cwd=cwd,
            input=input_text
        )
        return result.stdout, result.stderr, result.returncode
    except Exception as e:
        return "", str(e), 1

def test_ex00():
    """Test Exercise 00: BitcoinExchange"""
    print(f"\n{GREEN}{'='*50}{NC}")
    print(f"{GREEN}EXERCISE 00: BitcoinExchange{NC}")
    print(f"{GREEN}{'='*50}{NC}\n")
    
    os.chdir('ex00')
    
    # Compile
    print(f"{YELLOW}Compiling...{NC}")
    stdout, stderr, ret = run_command("make re")
    if ret != 0:
        print(f"{RED}Compilation failed!{NC}")
        print(stderr)
        os.chdir('..')
        return False
    print(f"{GREEN}Compilation successful!{NC}\n")
    
    # Create data.csv if it doesn't exist
    if not os.path.exists('data.csv'):
        print(f"{YELLOW}Creating data.csv...{NC}")
        with open('data.csv', 'w') as f:
            f.write("""date,exchange_rate
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
""")
    
    tests = [
        {
            "name": "Valid inputs",
            "input": "date | value\n2011-01-03 | 3\n2012-01-11 | 2\n2013-01-09 | 1\n",
            "should_pass": True
        },
        {
            "name": "Invalid date format",
            "input": "date | value\n2011-13-03 | 3\n2012-01-32 | 2\n",
            "should_pass": False
        },
        {
            "name": "Negative value",
            "input": "date | value\n2011-01-03 | -1\n",
            "should_pass": False
        },
        {
            "name": "Too large value",
            "input": "date | value\n2011-01-03 | 1001\n",
            "should_pass": False
        },
        {
            "name": "Boundary values (0, 1000)",
            "input": "date | value\n2011-01-03 | 0\n2012-01-11 | 1000\n",
            "should_pass": True
        },
        {
            "name": "Leap year validation",
            "input": "date | value\n2020-02-29 | 1\n2021-02-29 | 1\n",
            "should_pass": False  # 2021 is not a leap year
        },
    ]
    
    for i, test in enumerate(tests, 1):
        print(f"{YELLOW}Test {i}: {test['name']}{NC}")
        with open('test_input.txt', 'w') as f:
            f.write(test['input'])
        
        stdout, stderr, ret = run_command("./btc test_input.txt")
        print(stdout)
        if stderr:
            print(stderr)
        print()
    
    # Test without arguments
    print(f"{YELLOW}Test: No arguments{NC}")
    stdout, stderr, ret = run_command("./btc")
    print(stdout if stdout else stderr)
    print()
    
    # Cleanup
    if os.path.exists('test_input.txt'):
        os.remove('test_input.txt')
    
    os.chdir('..')
    return True

def test_ex01():
    """Test Exercise 01: RPN Calculator"""
    print(f"\n{GREEN}{'='*50}{NC}")
    print(f"{GREEN}EXERCISE 01: RPN Calculator{NC}")
    print(f"{GREEN}{'='*50}{NC}\n")
    
    os.chdir('ex01')
    
    # Compile
    print(f"{YELLOW}Compiling...{NC}")
    stdout, stderr, ret = run_command("make re")
    if ret != 0:
        print(f"{RED}Compilation failed!{NC}")
        print(stderr)
        os.chdir('..')
        return False
    print(f"{GREEN}Compilation successful!{NC}\n")
    
    tests = [
        ("Simple: 8 9 * 9 - 9 - 9 - 4 - 1 +", "8 9 * 9 - 9 - 9 - 4 - 1 +", True, "42"),
        ("Simple: 7 7 * 7 -", "7 7 * 7 -", True, "42"),
        ("Simple: 3 4 +", "3 4 +", True, "7"),
        ("Division: 9 3 /", "9 3 /", True, "3"),
        ("Only digits: 0 1 +", "0 1 +", True, "1"),
        ("Only digits: 9 9 +", "9 9 +", True, "18"),
        ("Multi-digit (should fail): 10 2 +", "10 2 +", False, ""),
        ("Invalid operator: 1 2 %", "1 2 %", False, ""),
        ("Division by zero: 5 0 /", "5 0 /", False, ""),
        ("Not enough operands: 1 +", "1 +", False, ""),
        ("Too many operands: 1 2 3 +", "1 2 3 +", False, ""),
        ("All operators +", "5 3 +", True, "8"),
        ("All operators -", "5 3 -", True, "2"),
        ("All operators *", "5 3 *", True, "15"),
        ("All operators /", "6 3 /", True, "2"),
    ]
    
    for i, (name, expr, should_pass, expected) in enumerate(tests, 1):
        print(f"{YELLOW}Test {i}: {name}{NC}")
        stdout, stderr, ret = run_command(f'./RPN "{expr}"')
        result = stdout.strip() if stdout else stderr.strip()
        print(f"Input: {expr}")
        print(f"Output: {result}")
        if should_pass and expected:
            if result == expected:
                print(f"{GREEN}✓ Correct{NC}")
            else:
                print(f"{RED}✗ Expected {expected}, got {result}{NC}")
        print()
    
    # Test without arguments
    print(f"{YELLOW}Test: No arguments{NC}")
    stdout, stderr, ret = run_command("./RPN")
    print(stdout if stdout else stderr)
    print()
    
    os.chdir('..')
    return True

def test_ex02():
    """Test Exercise 02: PmergeMe"""
    print(f"\n{GREEN}{'='*50}{NC}")
    print(f"{GREEN}EXERCISE 02: PmergeMe{NC}")
    print(f"{GREEN}{'='*50}{NC}\n")
    
    os.chdir('ex02')
    
    # Compile
    print(f"{YELLOW}Compiling...{NC}")
    stdout, stderr, ret = run_command("make re")
    if ret != 0:
        print(f"{RED}Compilation failed!{NC}")
        print(stderr)
        os.chdir('..')
        return False
    print(f"{GREEN}Compilation successful!{NC}\n")
    
    tests = [
        ("Simple sequence", "3 5 9 7 4", True),
        ("Already sorted", "1 2 3 4 5", True),
        ("Reverse sorted", "9 8 7 6 5 4 3 2 1", True),
        ("Single element", "42", True),
        ("Two elements", "2 1", True),
        ("Duplicates", "5 5 5 5 5", True),
        ("Large numbers", "2147483647 1 999999999 42", True),
        ("Larger sequence", "15 8 23 4 16 42 11 9 27 3 19 7 31 2 13 5 29 1 17 21", True),
        ("Including zero", "0 5 3 8 1", True),
        ("Negative (should fail)", "1 -2 3", False),
        ("Non-numeric (should fail)", "1 abc 3", False),
    ]
    
    for i, (name, args, should_pass) in enumerate(tests, 1):
        print(f"{YELLOW}Test {i}: {name}{NC}")
        stdout, stderr, ret = run_command(f"./PmergeMe {args}")
        print(stdout)
        if stderr:
            print(stderr)
        print()
    
    # Test without arguments
    print(f"{YELLOW}Test: No arguments{NC}")
    stdout, stderr, ret = run_command("./PmergeMe")
    print(stdout if stdout else stderr)
    print()
    
    os.chdir('..')
    return True

def main():
    """Main test runner"""
    print(f"{BLUE}{'='*50}{NC}")
    print(f"{BLUE}CPP09 Comprehensive Test Suite{NC}")
    print(f"{BLUE}{'='*50}{NC}")
    
    # Save original directory
    original_dir = os.getcwd()
    
    try:
        # Change to cpp09 directory
        os.chdir('/Users/hel-omra/Documents/CPP/cpp09')
        
        test_ex00()
        test_ex01()
        test_ex02()
        
        print(f"\n{BLUE}{'='*50}{NC}")
        print(f"{BLUE}All tests completed!{NC}")
        print(f"{BLUE}{'='*50}{NC}")
        
    except Exception as e:
        print(f"{RED}Error: {e}{NC}")
        import traceback
        traceback.print_exc()
    finally:
        os.chdir(original_dir)

if __name__ == "__main__":
    main()
