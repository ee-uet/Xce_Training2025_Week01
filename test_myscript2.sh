#!/bin/bash
output=$(./my_script2.sh 3 5)
if [[ "$output" == "Sum: 8" ]]; then
    echo "test_myscript2: PASS"
    exit 0
else
    echo "test_myscript2: FAIL"
    exit 1
fi
