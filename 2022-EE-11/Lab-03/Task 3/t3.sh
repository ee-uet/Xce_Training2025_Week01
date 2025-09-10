#!/bin/bash

factorial() {
    local num=$1
    local result=1
    
    # Calculate factorial
    for ((i=1; i<=num; i++)); do
        result=$((result * i))
    done
    
    echo "Factorial of $num is: $result"
}

factorial 5
factorial 0
factorial 7
factorial 10
echo


fruits=("apple" "banana" "orange" "grape" "strawberry")

print_fruits() {
    echo "Fruits in the array:"
    for i in "${!fruits[@]}"; do
        echo "$((i+1)). ${fruits[i]}"
    done
    echo "Total fruits: ${#fruits[@]}"
}

print_fruits
echo

fruits+=("mango")
echo "Added 'mango' to the array:"
print_fruits
echo


declare -A countries
countries=(
    ["USA"]="Washington D.C."
    ["UK"]="London"
    ["France"]="Paris"
    ["Germany"]="Berlin"
    ["Japan"]="Tokyo"
    ["Canada"]="Ottawa"
    ["Australia"]="Canberra"
    ["India"]="New Delhi"
)

get_capital() {
    local country="$1"
    
    # Convert to uppercase for case-insensitive matching
    country=$(echo "$country" | tr '[:lower:]' '[:upper:]')
    
    if [[ -n "${countries[$country]}" ]]; then
        echo "The capital of $country is: ${countries[$country]}"
    else
        echo "Error: Country '$country' not found in database"
        echo "Available countries: ${!countries[@]}"
    fi
}

# Test the function
echo "Testing country-capital lookup:"
get_capital "USA"
get_capital "japan"
get_capital "Spain" # Not in the list
echo