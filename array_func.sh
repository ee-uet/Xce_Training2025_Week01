#!/bin/bash
arr_fruit=("banana" "apple" "mango" "pineapple" "watermellon")

func_array() {
	echo "Following are the fruits"
	for ((i=0; i<${#arr_fruit[@]}; i++))
	do
		echo "$i: ${arr_fruit[$i]}"
	done
}
func_array
