#!/bin/bash

output=$(./scrips/script_2.sh)
if [ "$output" == "Hello from script_2" ];
then 
    echo "Test for script_2 is passed"
else
    echo "Test for script_2 is failed"
fi

