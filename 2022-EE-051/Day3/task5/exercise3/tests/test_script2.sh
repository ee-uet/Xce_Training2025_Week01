#!/bin/bash
output=$(bash ./script2.sh)
if [ "$output" = "Hello from script2" ]; then
    echo "test_script2.sh: PASS"
else
    echo "test_script2.sh: FAIL"
    exit 1
fi

