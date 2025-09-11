#!/bin/bash
# Test for even_odd.sh
echo ""
echo "Running test_even_odd.sh..."

output=$(./E2_1.sh 4)
if [[ "$output" == "Number is even" ]]; then
    echo "Test passed: 4 is even"
else
    echo "Test failed: '$output'"
    exit 1
fi

output=$(./E2_1.sh 7)
if [[ "$output" == "Number is Odd" ]]; then
    echo "Test passed: 7 is odd"
else
    echo "Test failed: '$output'"
    exit 1
fi
echo ""
