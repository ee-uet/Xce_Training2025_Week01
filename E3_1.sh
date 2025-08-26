#!/bin/bash

    
function fict(){
    local num=$1
    if [ $num -eq 1 ]; then
        echo 1
    else 
        local prev=$(fict $((num-1)))
        echo $((num*prev))
    fi
} 
echo "Enter number"
read a
echo "Factorial of $a is: $(fict $a) "
