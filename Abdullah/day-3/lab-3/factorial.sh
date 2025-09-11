#!/bin/bash

# Exercise 3.1: Functions
function factorial() {
    local num=$1
    local result=1

    for ((count=1; count<=num; count++))    # Loop through numbers 1 to num
    do
        result=$((result * count))          # Calculate factorial
    done
    echo $result
}

read -p "Enter number to know its factorial: " NUM
result=$(factorial $NUM)
echo "The factorial of $NUM is $result"