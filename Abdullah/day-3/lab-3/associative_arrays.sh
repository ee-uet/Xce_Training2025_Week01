#!/bin/bash

# Exercise 3.3: Associative Arrays
declare -A country_pairs    # Declare an associative array
country_pairs=( [Pakistan]="Islamabad" [India]="Delhi" [China]="Beijing" )

function get_capital(){
    read -p "Enter the Country name: " country

    found=false
    for country_name in "${!country_pairs[@]}"; do  # Iterate over keys
        if [[ "$country" == "$country_name" ]]; then   # Check for match
            echo "Country: $country, Capital: ${country_pairs[$country]}"
            found=true
            break
        fi
    done

    if [[ "$found" == false ]]; then
        echo "Your Country is not in the list!"
        echo "Available countries: ${!country_pairs[@]}"   # Display available countries
    fi
}

get_capital # Call the function to execute