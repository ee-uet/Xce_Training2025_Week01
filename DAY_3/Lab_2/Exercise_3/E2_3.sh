#!/bin/bash

random=$(((RANDOM % 10) + 1))
guess=0

echo "Guess a number between 1 and 10:"
while [ $guess -ne $random ]
do
    echo "Enter guess number: "
    read guess
    if [ $guess -lt $random ]; then
        echo "Your guess is lower"
    elif [ $guess -gt $random ]; then 
        echo "Your guess is higher"
    else
        echo "Your guess is right"
    fi
done