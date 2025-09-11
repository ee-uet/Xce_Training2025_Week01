#!/bin/bash

# -A specifies that capitals is an associative array 
declare -A capitals
capitals=(  
    ["Pakistan"]="Islamabad" 
    ["India"]="New Dehli" 
    ["Chaina"]="Beijing" 
    ["Japan"]="Tokyo" 
    ["America"]="Washington, D.C." 
)

function get_capital(){
    echo "Enter the name of Country: "
    read country
    
    # -v checks if a variable exists
    if [[ -v capitals[$country] ]]; then
        echo "The capital of $country is: ${capitals[$country]}"
    else
        echo "Sorry, this country is not in my array"
    fi
}

get_capital