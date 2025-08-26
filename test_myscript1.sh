#!/bin/bash
output=$(./my_script1.sh)
if [[ "$output" == "Hello from myscript1!" ]]; then
    echo "test_myscript1: PASS"
    exit 0
else
    echo "test_myscript1: FAIL"
    exit 1
fi
