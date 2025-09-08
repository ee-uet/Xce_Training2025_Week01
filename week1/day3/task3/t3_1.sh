#!/bin/bash

ans=1
read -p "Enter Number: " F

# function definition
function factorial() {
    # loop multiplies numbers from 1..F
    for (( i=1; i<=$F; i++ ))
    do
        ans=$((ans * i))
    done
    echo "Factorial is: ${ans}"
}

factorial

