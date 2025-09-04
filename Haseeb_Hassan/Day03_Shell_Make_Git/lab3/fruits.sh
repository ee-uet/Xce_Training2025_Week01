#!/bin/bash
fruits=("banana" "apple" "pemogranate" "guava")

print_fruits(){

	for i in "${fruits[*]}"
	do
		echo "$i"
	done
}

print_fruits
fruits+=("Orange")
print_fruits
