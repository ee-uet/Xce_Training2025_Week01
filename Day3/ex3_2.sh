#!/bin/bash

FRUITS=("apple" "Orange" "Mango")
function fruits() {
    echo "List of fruits:"
    for fruit in "${FRUITS[@]}"
       do
       echo "$fruit"
       done
}
read -p "Enter a new fruit_name: " new_fruit
FRUITS+=("$new_fruit")
fruits