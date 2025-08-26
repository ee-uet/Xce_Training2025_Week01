#!/bin/bash
num=$((RANDOM % 10))
echo "guess a number"
read guess
while [ $guess -ne $num ]
do
	if [ $guess -lt $num ]
	then
		echo "Too Low,guess another number"
                read guess
	else
		echo "Too high,guess another number"
		read guess
	fi
done
echo "Congrats! you guessed the right number"
