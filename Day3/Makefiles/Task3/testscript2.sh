#!/bin/bash

output=$(bash ./script2.sh)
if [[ "$output" == "This is script 2" ]]; then
    echo "script2.sh test passed"
else
    echo "script2.sh test failed"
    exit 1
fi
