#!/bin/bash

# Exercise 3.2: Arrays and Functions
# Create array of fruits
arr_fruit=("banana" "apple" "mango" "pineapple" "watermellon")

func_array() {
	echo "Following are the fruits"
	# Loop through array using array length ${#arr_fruit[@]}
	for ((i=0; i<${#arr_fruit[@]}; i++))
	do
		echo "$i: ${arr_fruit[$i]}"
	done
}

# Call the function to display fruits
func_array
