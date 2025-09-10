#!/bin/bash

# Test hello.sh
output=$(../scripts/hello.sh)
expected="Hello, World!"
if [[ "$output" == "$expected" ]]; then
    echo "Test passed: hello.sh outputs '$expected'"
    exit 0
else
    echo "Test failed: hello.sh outputs '$output', expected '$expected'" >&2
    exit 1
fi
