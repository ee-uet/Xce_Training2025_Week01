#!/bin/bash

output=$(./scrips/script_3.sh)
if [ "$output" == "Hello from script_3" ];
then 
    echo "Test for script_3 is passed"
else
    echo "Test for script_3 is failed"
fi

