#!/bin/bash

# declare associative array
declare -A capitals

capitals=(
    ["USA"]="Washington, DC"
    ["Pakistan"]="Islamabad"
    ["India"]="New Delhi"
    ["France"]="Paris"
)

get_capital() {
    read -p "Enter a Country Name: " C

    # -v checks if key exists in associative array
    if [ -v capitals["$C"] ]; then
        echo "The capital of ${C} is ${capitals[$C]}"
    else
        echo "The capital of ${C} is not in the data"
    fi   
}

get_capital

