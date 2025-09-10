#!/bin/bash
# Unit tests for calculator.sh

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
CALCULATOR="$SCRIPT_DIR/../scripts/calculator.sh"

# Test counter
TESTS_RUN=0
TESTS_PASSED=0

run_test() {
    local test_name=$1
    local expected=$2
    shift 2
    local result
    
    TESTS_RUN=$((TESTS_RUN + 1))
    
    if result=$(bash "$CALCULATOR" "$@" 2>&1); then
        if [ "$result" = "$expected" ]; then
            echo "✓ $test_name"
            TESTS_PASSED=$((TESTS_PASSED + 1))
        else
            echo "✗ $test_name - Expected: '$expected', Got: '$result'"
        fi
    else
        echo "✗ $test_name - Script execution failed"
    fi
}

echo "Running calculator tests..."

# Test addition
run_test "Addition test" "8" "add" "5" "3"

# Test subtraction
run_test "Subtraction test" "2" "subtract" "5" "3"

# Test multiplication
run_test "Multiplication test" "15" "multiply" "5" "3"

# Test division
run_test "Division test" "2" "divide" "6" "3"

# Test division by zero
run_test "Division by zero test" "Error: Division by zero" "divide" "5" "0"

echo ""
echo "Tests run: $TESTS_RUN"
echo "Tests passed: $TESTS_PASSED"
echo "Tests failed: $((TESTS_RUN - TESTS_PASSED))"

if [ $TESTS_PASSED -eq $TESTS_RUN ]; then
    echo "All tests passed!"
    exit 0
else
    echo "Some tests failed!"
    exit 1
fi