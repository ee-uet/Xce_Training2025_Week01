#!/bin/bash
# Unit tests for file_utils.sh

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
FILE_UTILS="$SCRIPT_DIR/../scripts/file_utils.sh"
TEST_FILE="/tmp/test_file_$$"

# Test counter
TESTS_RUN=0
TESTS_PASSED=0

setup() {
    echo "This is a test file" > "$TEST_FILE"
    echo "Line 2" >> "$TEST_FILE"
    echo "Line 3" >> "$TEST_FILE"
}

cleanup() {
    rm -f "$TEST_FILE" "${TEST_FILE}.bak."*
}

run_test() {
    local test_name=$1
    local expected=$2
    shift 2
    local result
    
    TESTS_RUN=$((TESTS_RUN + 1))
    
    if result=$(bash "$FILE_UTILS" "$@" 2>&1); then
        if [[ "$result" == *"$expected"* ]]; then
            echo "✓ $test_name"
            TESTS_PASSED=$((TESTS_PASSED + 1))
        else
            echo "✗ $test_name - Expected to contain: '$expected', Got: '$result'"
        fi
    else
        echo "✗ $test_name - Script execution failed"
    fi
}

echo "Running file utils tests..."

setup

# Test line counting
run_test "Line count test" "3" "count" "$TEST_FILE"

# Test backup creation
run_test "Backup test" "Backup created" "backup" "$TEST_FILE"

# Test error handling
run_test "File not found test" "Error: File" "count" "/nonexistent/file"

cleanup

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