#!/bin/bash

Fruits=("apple" "banana" "orange")

function fruit_print(){
    echo "Fruits in array: "
    for fruit in "${Fruits[@]}"; do
    echo "$fruit"
    done
}

fruit_print 
echo "-----------------------"
Fruits+=("pineapple")

fruit_print