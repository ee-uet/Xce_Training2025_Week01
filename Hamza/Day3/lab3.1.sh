#!/bin/bash

# A function to calculate the factorial
function calculate_factorial() {
    local num=$1
    local factorial=1
    for ((i=1; i<=num; i++))
    do
        factorial=$((factorial * i))
    done
    echo "Faktoryal $num ka hai: $factorial"
}

echo "Chalo, faktoryal nikalte hain!"
calculate_factorial 5
calculate_factorial 7
calculate_factorial 10
