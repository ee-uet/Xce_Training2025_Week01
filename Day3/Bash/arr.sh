#!/bin/bash

# creating array
array=("apple" "banana" "mango" "orange")

echo "The array elements are: "

# function
arr() {
	for ((i = 0; i < ${#array[@]}; i++)); do
		echo "${array[i]}"
	done
}
arr

echo
echo "New array elements are: "

array[4]="pineapple"

arr
