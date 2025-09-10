#!/bin/bash

declare -A asso_array

asso_array["Pakistan"]="Islamabad"
asso_array["Japan"]="Tokyo"
asso_array["France"]="Paris"
asso_array["USA"]="Washington D.C."

echo "Capital of Pakistan: ${asso_array[Pakistan]}"
echo "Capital of Japan: ${asso_array[Japan]}"

function foo() {
    read -p "Enter Country name: " name
    
    # Check if the country exists in the array
    if [[ -v asso_array["$name"] ]]; then
        echo "Capital of $name: ${asso_array[$name]}"
    else
        echo "Error: '$name' not found in the database!"
        echo "Available countries: ${!asso_array[@]}"
        return 1  # Return error code
    fi
}

foo