#!/bin/bash

# Exercise 2.3: While Loop - Number Guessing Game
# Generate random number between 1 and 10
secret=$(( (RANDOM % 10) + 1 ))

echo "Guess number between 1 and 10"
read -p ">" number

# Continue until user guesses correctly
while (( number != secret))
do
	if (( number < secret)); then
		echo "Higher"
	else
		echo "Lower"
	fi
	echo "Guess again"
	read -p ">" number
done
echo "Yes!"
