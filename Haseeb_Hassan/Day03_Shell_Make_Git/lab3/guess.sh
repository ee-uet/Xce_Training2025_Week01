#!/bin/bash
target=$(( RANDOM % 10 + 1 ))
echo "Guess a number between 1 and 10"
guess=0

while (( guess != target ))
do
    read -p "Enter your guess: " guess
    if (( guess < target )); then
        echo "Guess is low"
    elif (( guess > target )); then
        echo "Guess is high"
    else
        echo " Correct! The number was $target"
    fi
done
