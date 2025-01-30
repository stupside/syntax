#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Path to your executable
PARSER="./out/bin/syntax"

# Counter for passed and failed tests
PASSED=0
FAILED=0
TEST_NUM=0

# Function to run a test case
run_test() {
    local expression="$1"
    local expected_code="$2"
    local expected_output="$3"
    local description="$4"
    ((TEST_NUM++))

    # Run the parser and capture both output and exit code
    output=$($PARSER "$expression" 2>&1)
    exit_code=$?
    
    if [ $exit_code -eq $expected_code ] && \
       ([ $expected_code -eq 1 ] || [ "$output" = "INT($expected_output)" ]); then
        echo -e "${GREEN}[$TEST_NUM] PASS${NC} $description ($expression)"
        ((PASSED++))
    else
        echo -e "${RED}[$TEST_NUM] FAIL${NC} $description"
        echo "  Input: '$expression'"
        echo "  Expected: $([ $expected_code -eq 0 ] && echo "INT($expected_output)" || echo "error")"
        echo "  Got: $([ $exit_code -eq 0 ] && echo "$output" || echo "error (code $exit_code)")"
        ((FAILED++))
    fi
}

echo -e "${BLUE}Starting Basic Tests${NC}"
# Basic valid test cases
run_test "2+3" 0 "5" "Simple addition"
run_test "2*3" 0 "6" "Simple multiplication"
run_test "(2+3)" 0 "5" "Parenthesized addition"
run_test "42" 0 "42" "Single number"
run_test "0" 0 "0" "Zero value"
run_test "1+1" 0 "2" "Simple addition with ones"
run_test "1+2+3" 0 "6" "Multiple additions"
run_test "3*3*3" 0 "27" "Multiple multiplications"

echo -e "\n${BLUE}Starting Complex Tests${NC}"
# Complex valid test cases
run_test "2+3*4" 0 "14" "Operator precedence"
run_test "(2+3)*4" 0 "20" "Parentheses precedence"
run_test "2*3+4*5" 0 "26" "Multiple operations"
run_test "((2+3)*4)" 0 "20" "Nested parentheses"
run_test "5+6*9+(9+87)" 0 "155" "Complex expression"
run_test "(2+3)*(4+5)" 0 "45" "Multiple grouped expressions"
run_test "9*(8+7*(6+5))" 0 "765" "Complex nested expression"
run_test "2+3*4+1" 0 "15" "Mixed operators with precedence"
run_test "(5+2)*3+4" 0 "25" "Parentheses with mixed operators"
run_test "2*(3+4)*(5+6)" 0 "154" "Multiple parentheses multiplication"
run_test "(1+2)*(3+4)*(5+6)" 0 "231" "Three grouped expressions"

echo -e "\n${BLUE}Starting Edge Cases${NC}"
# Edge cases with spaces and formatting
run_test "1234567890" 0 "1234567890" "Large number"
run_test "1+2+3+4+5+6+7+8+9+0" 0 "45" "Long expression"
run_test "((((1+2)+3)+4)+5)" 0 "15" "Many nested parentheses"
run_test "0000001" 0 "1" "Leading zeros"
run_test "99999999" 0 "99999999" "Large number sequence"
run_test "(((((1)))))" 0 "1" "Many redundant parentheses"
run_test "1" 0 "1" "Single digit"
run_test "2*(1+1)" 0 "4" "Simple with parentheses"
run_test "(((2+3)+(4+5)))" 0 "14" "Multiple nested groups"

echo -e "\n${BLUE}Testing Space Handling${NC}"
# Space tests (should all fail)
run_test " 2+3" 1 "" "Leading space"
run_test "2+3 " 1 "" "Trailing space"
run_test "2 +3" 1 "" "Space before operator"
run_test "2+ 3" 1 "" "Space after operator"
run_test "  2  +  3  " 1 "" "Multiple spaces"
run_test "2+    3" 1 "" "Multiple spaces between tokens"
run_test "   2+3   " 1 "" "Both leading and trailing spaces"

echo -e "\n${BLUE}Starting Invalid Tests${NC}"
# Invalid test cases
run_test "2+" 1 "" "Incomplete expression"
run_test "2)" 1 "" "Mismatched right parenthesis"
run_test "(2" 1 "" "Mismatched left parenthesis"
run_test "2**3" 1 "" "Double operator"
run_test "a+b" 1 "" "Invalid characters"
run_test "" 1 "" "Empty input"
run_test "((()))" 1 "" "Empty nested parentheses"
run_test "2+(3*)" 1 "" "Incomplete nested expression"
run_test "2+3+" 1 "" "Trailing operator"
run_test "*2+3" 1 "" "Leading operator"
run_test "()" 1 "" "Empty parentheses"
run_test "3++4" 1 "" "Consecutive operators"
run_test "2,3" 1 "" "Invalid separator"
run_test "0x123" 1 "" "Hexadecimal number"
run_test "2^3" 1 "" "Invalid operator"
run_test "((2+3)" 1 "" "Unmatched left parentheses"
run_test "(2+3))" 1 "" "Unmatched right parentheses"
run_test "(*2+3)" 1 "" "Invalid expression in parentheses"
run_test "2(3+4)" 1 "" "Missing multiplication operator"
run_test "(2+3)(4+5)" 1 "" "Missing operator between groups"

# echo -e "\n${BLUE}Starting Boundary Tests${NC}"
# run_test "2147483647" 0 "2147483647" "Maximum 32-bit integer"
# run_test "2147483648" 1 "" "Overflow 32-bit integer"

# Print summary
echo "========================================="
echo -e "${BLUE}Summary: ${GREEN}$PASSED passed${NC}, ${RED}$FAILED failed${NC} (Total: $((PASSED + FAILED)))${NC}"
[ $FAILED -eq 0 ] || exit 1