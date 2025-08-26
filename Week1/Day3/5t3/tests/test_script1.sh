#!/bin/bash
output=$(bash ./script1.sh)
if [ "$output" = "Hello from script1" ]; then
    echo "test_script1.sh: PASS"
else
    echo "test_script1.sh: FAIL"
    exit 1
fi

