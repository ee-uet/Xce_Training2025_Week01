#!/bin/bash
output=$(bash ./script3.sh)
if [ "$output" = "Hello from script3" ]; then
    echo "test_script3.sh: PASS"
else
    echo "test_script3.sh: FAIL"
    exit 1
fi

