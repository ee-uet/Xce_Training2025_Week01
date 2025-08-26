#!/bin/bash

declare -A country_pairs
country_pairs=( [Pakistan]="Islamabad" [India]="Delhi" [China]="Beijing" )

function capital(){
    read -p "Enter the Country name: " country

    found=false
    for country_name in "${!country_pairs[@]}"; do
        if [[ "$country" == "$country_name" ]]; then
            echo "Country: $country, Capital: ${country_pairs[$country]}"
            found=true
            break
        fi
    done

    if [[ "$found" == false ]]; then
        echo "Your Country is not in the list!"
        echo "Exiting the program."
    fi
}

capital
