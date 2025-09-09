#!/bin/bash

# Exercise 3.3: Associative Arrays
# Declare associative array for country-capital pairs
declare -A associ_arr

# Populate associative array with key-value pairs
associ_arr["Pakistan"]="Islamabad"
associ_arr["India"]="Delhi"
associ_arr["China"]="Beijing"
associ_arr["Japan"]="Tokyo"

func_assos_arr() {
	# Check if key exists in associative array
	if [[ -v associ_arr[$1] ]]; then
		echo "Capital of $1 is ${associ_arr[$1]}"
	else
		echo "I don't know"
	fi
}

# Call function with command-line argument
func_assos_arr "$1"
