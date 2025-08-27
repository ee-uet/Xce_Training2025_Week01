#!/bin/bash

declare -A Capitals

Capitals["Pakistan"]="Islamabad"
Capitals["India"]="New Dehli"
Capitals["America"]="Washington DC"
Capitals["China"]="Beijing"
Capitals["Japan"]="Tokyo"
Capitals["Russia"]="Moscow"

assocArr() {

	read -p "Enter Country name: " name

	if [[ -v Capitals["$name"] ]]; then
		echo "Country: $name, its capital is: ${Capitals[$name]}"

	else
		echo "Error! Not in array"
	fi
}

assocArr
