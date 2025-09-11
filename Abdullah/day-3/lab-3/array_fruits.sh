#!/bin/bash

# Exercise 3.2: Arrays
FRUITS=("apple" "Orange" "Mango") # Initial array of fruits

function print_fruits() {
    echo "List of fruits:"
    for fruit in "${FRUITS[@]}"     # Loop through each fruit in the array
    do
        echo "$fruit"
    done
}

echo "Initial fruits:"
print_fruits

read -p "Enter a new fruit name: " new_fruit
FRUITS+=("$new_fruit")

echo ""
echo "Updated fruits:"
print_fruits