#!/bin/bash

# Exercise 2.3: While Loop
min=1
max=10
num=$((RANDOM % (max - min + 1) + min))
read -p "Guess the number between $min and $max: " GUESS

while [ $GUESS -ne $num ]
do
    if [ $GUESS -gt $num ] ; then
        echo "Your guess is high"
    elif [ $GUESS -lt $num ] ; then
        echo "Your guess is low"
    fi
    read -p "Try Again: " GUESS
done
echo "You guessed correctly!"