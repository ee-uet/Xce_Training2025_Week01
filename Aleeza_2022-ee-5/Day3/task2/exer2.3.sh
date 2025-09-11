#!/bin/bash
num=$((RANDOM % 10)) #generate random number in range 0-9
echo "guess a number"#prompt user to gess a number
read guess           #store user's guess in guess variable
while [ $guess -ne $num ] # while user's guess is not equal to number
do
	if [ $guess -lt $num ] #give hints
	then
		echo "Too Low,guess another number"
                read guess
	else
		echo "Too high,guess another number"
		read guess
	fi
done
echo "Congrats! you guessed the right number" #print this if user guesses right
