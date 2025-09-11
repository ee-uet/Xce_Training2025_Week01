#!/bin/bash
declare -A capitals
capitals["pakistan"]="lahore"
capitals["america"]="new york"
capitals["indonesia"]="kaula lampur"
CHECK=1
function find_capital() {
    read -p "enter the country name and findout its capital: " USR_COUNTRY;
    for country_name in "${!capitals[@]}"; do
        if [ $country_name == $USR_COUNTRY ]; then
            echo "$USR_COUNTRY -> ${capitals[$country_name]}"
            CHECK=0;
            
        fi
    done
    if [ $CHECK -eq 1 ]; then
        echo "ERROR: entered country name does not exist in the database."
    fi

}
find_capital