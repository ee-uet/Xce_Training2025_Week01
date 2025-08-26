#!/bin/bash

declare -A capitals

capitals=(
    ["USA"]="Washington, DC"
    ["Pakistan"]="Islamabad"
    ["India"]="New Delhi"
    ["France"]="Paris"
)

get_capital()
    {
        read -p "Enter a Country Name: " C

        if [ -v capitals["$C"] ];
        then
        echo "The capital of country is ${capitals[$C]}"
        else
        echo "The Capital of ${C} is not in the data"
        fi   
    }
    get_capital