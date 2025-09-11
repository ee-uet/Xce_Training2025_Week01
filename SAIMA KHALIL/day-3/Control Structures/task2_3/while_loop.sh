#!/bin/bash
random_number=$((RANDOM % 10 + 1))
guess=0 
# Loop until the user guesses the correct number
while [ "$guess" -ne "$random_number" ]; do    
    read -p "Guess a number between 1 and 10: " guess
    if [ "$guess" -lt "$random_number" ]; then
        echo "High ha number tmara!"
    elif [ "$guess" -gt "$random_number" ]; then
        echo "Low ha number tmara!"       
    else
        echo "Congratulations! You guessed the number <3 $random_number."
    fi
done
