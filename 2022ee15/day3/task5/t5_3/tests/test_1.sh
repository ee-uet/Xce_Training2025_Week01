#!/bin/bash

output=$(./scrips/script_1.sh)
if [ "$output" == "Hello from script_1" ];
then 
    echo "Test for script_1 is passed"
else
    echo "Test for script_1 is failed"
fi

