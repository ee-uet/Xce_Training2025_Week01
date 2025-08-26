#!/bin/bash
# Script to calculate the factorial of a number
# Function to calculate factorial
factorial() {
    local num=$1 #argument1 
    local result=1
    while [ $num -gt 1 ]; do #-gt means greater than
        result=$((result * num))
        num=$((num - 1))
    done        
    echo $result
} 
# Read user input
read -p "Enter a number to calculate its factorial: " number
# Validate input
if ! [[ "$number" =~ ^[0-9]+$ ]] || [ "$number" -lt 0 ]; then #regex ha (^=starting of string, [0-9]+ = one or more digits, $= end of string)
    echo "Please enter a valid non-negative integer."
    exit 1 #script immediately stops at this point.
fi      
# Calculate and display the factorial
result=$(factorial "$number")
echo "The factorial of $number is $result."