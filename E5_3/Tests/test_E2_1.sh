#!/bin/bash
# Test for even_odd.sh

echo "Running test_even_odd.sh..."

output=$(./even_odd.sh 4)
if [[ "$output" == "Number is even" ]]; then
    echo "✅ Test passed: 4 is even"
else
    echo "❌ Test failed: Expected 'Number is even', got '$output'"
    exit 1
fi

output=$(./even_odd.sh 7)
if [[ "$output" == "Number is Odd" ]]; then
    echo "✅ Test passed: 7 is odd"
else
    echo "❌ Test failed: Expected 'Number is Odd', got '$output'"
    exit 1
fi
