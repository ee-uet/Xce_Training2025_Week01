#1. Create an associative array of country-capital pairs
#2. Write a function that asks the user for a country and returns its capital
#3. Implement error handling for countries not in the array

#!/bin/bash
# Create an associative array of country-capital pairs
declare -A capitals
capitals=(
    ["Pakistan"]="Islamabad"
    ["Japan"]="Tokyo"
    ["India"]="New Delhi"
    ["China"]="Beijing"
)
# Function to get the capital of a country
get_capital() {
    local country=$1
    if [[ -n "${capitals[$country]}" ]]; then # -n checks if the string is non-empty
        echo "The capital of $country is: ${capitals[$country]}"
    else
        echo "Error: Capital for $country not found."
    fi
}        
echo "Enter a country name to find its capital:"
read country 

get_capital "$country" 