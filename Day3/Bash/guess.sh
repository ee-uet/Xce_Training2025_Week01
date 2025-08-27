#!/bin/bash

# input from user
read -p "Enter a number: " guess

# random number generation
number=$((RANDOM % 10 + 1))

while [ $number -ne $guess ]; do
	if [ $number -lt $guess ]; then
		read -p "Too high, guess again: " guess
	else
		read -p "Too low, guess again: " guess
	fi
done

if [ $number -eq $guess ]; then
	echo "You guessed it right, it was $number"
fi

