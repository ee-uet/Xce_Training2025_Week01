#!/bin/bash
# Test for guess.sh (non-interactive)

echo "Running test_guess.sh..."

# Provide input automatically with "here string"
output=$(./guess.sh <<< "5")

if [[ "$output" == *"Guess a number between 1 and 10:"* ]]; then
    echo "✅ Test passed: script runs and prompts correctly"
else
    echo "❌ Test failed: script did not prompt correctly"
    exit 1
fi
