#!/bin/bash
output=$(~/c_codes/lab3/task5_3/task1_.sh)
if [ "$output" = "hello_world!" ]; then
    echo "task1_1.sh test passed"
else
    echo "task1_1.sh test failed"
    exit 1
fi