#!/bin/bash

source scripts/math_ops.sh

test_add() {
    result=$(add 2 3)
    if [ "$result" -eq 5 ]; then
        echo "add test passed"
    else
        echo "add test failed: expected 5, got $result"
        exit 1
    fi
}

test_multiply() {
    result=$(multiply 2 3)
    if [ "$result" -eq 6 ]; then
        echo "multiply test passed"
    else
        echo "multiply test failed: expected 6, got $result"
        exit 1
    fi
}

test_add
test_multiply
echo "All math tests passed!"