#!/bin/bash

output=$(bash ./script1.sh)
if [[ "$output" == "This is script 1" ]]; then
    echo "script1.sh test passed"
else
    echo "script1.sh test failed"
    exit 1
fi
