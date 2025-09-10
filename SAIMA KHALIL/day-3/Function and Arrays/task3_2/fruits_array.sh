#!/bin/bash
fruits=("Apple" "Banana" "Cherry" "Date")
print_fruits() {
    echo "Fruits in the array:"
    for fruit in "${fruits[@]}"; do #@ means all elements of the array
        echo "- $fruit"
    done
}   
print_fruits
fruits+=("Kiwi")  
print_fruits    
