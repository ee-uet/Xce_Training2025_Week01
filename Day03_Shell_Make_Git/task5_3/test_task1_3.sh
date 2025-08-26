#!/bin/bash
output=$(~/c_codes/lab3/task5_3/task1_3.sh)
if [ "$output" = 3 ]; then
    echo "task1_3.sh test passed"
else
    echo "task1_3.sh test failed"
    exit 1
fi