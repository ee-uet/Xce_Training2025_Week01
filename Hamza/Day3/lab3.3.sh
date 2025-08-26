#!/bin/bash

declare -A capitals
capitals[Pakistan]="Islamabad"
capitals[India]="New Delhi"
capitals[China]="Beijing"

echo "Chalo, capitals ka game khelein!"

find_capital() {
    read -p "Kis mulk ka capital chahiye? " country
    if [[ -v capitals[$country] ]]; then
        echo "$country ka capital hai... ${capitals[$country]}!"
    else
        echo "Afsos, $country hamari list mein nahi hai."
    fi
}

find_capital