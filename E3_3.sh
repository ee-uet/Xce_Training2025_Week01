#!/bin/bash

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

    if [[ -v capitals[$country] ]]; then
        echo "The capital of $country is: ${capitals[$country]}"
    else
        echo "Sorry, this country is not in my array"
    fi
}

get_capital