#!/bin/bash

# Exercise 3.1: Recursive Factorial Function
factorial() {
	# Base cases: 0! = 1 and 1! = 1
	if (( $1 == 0 | $1 == 1)); then
		echo 1
	else
		# Recursive case: n! = n * (n-1)!
		local prev=$(factorial $(($1 - 1)))
		echo $(( $1 * prev))
	fi
}

# Test factorial function with numbers 0-4
for (( i=0; i<5; i++))
do
	result=$(factorial $i)
	echo "Factorial of $i is $result"
done
