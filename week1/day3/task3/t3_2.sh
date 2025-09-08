#!/bin/bash

# indexed array
fruits=("Apple" "Banana" "Orange")

# function to print array elements
function arr() {
    for fruit in "${fruits[@]}";
    do
        echo "${fruit}"
    done   
}

arr

# add a new element using +=
fruits+=("Mango")
echo "Add one more fruit in array"
echo "${fruits[@]}"

