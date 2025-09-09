#!/bin/bash

# Exercise 2.1: Even/Odd Checker
# Check if number is odd using modulo operator
if (( $1 % 2 != 0 )); then
	echo "The number is odd"
else
	echo "The number is even"
fi
