#!/bin/bash
# Test for multiples.sh

echo "Running test_multiples.sh..."

output=$(./multiples.sh 2 | head -n 2)

expected="First 10 multiple of 2 is
2 * 1 = 2"

if [[ "$output" == "$expected" ]]; then
    echo "✅ Test passed: multiples of 2"
else
    echo "❌ Test failed: Expected:
$expected
Got:
$output"
    exit 1
fi
