#!/bin/bash	

# Even/Odd checker
read -p "Enter a number: " num
if (( $num % 2 == 0 )); then
    echo "Even"
else
    echo "Odd"
fi

echo

# Multiples calculator
read -p "Enter a number: " num
echo "The 1st 10 multiples of $num are:"
for (( i=1; i<=10; i++ ))
do
    mul=$((num * i))
    echo "$mul"
done

echo

# Guessing game
num=$((RANDOM % 10 + 1))
read -p "This is a guessing game, enter a number: " guess
while true
do
    if [ $guess -lt $num ]; then
        echo "Too low!"
        read -p "Guess: " guess
    elif [ $guess -gt $num ]; then
        echo "Too high!"
        read -p "Guess: " guess
    else
        echo "You got it! The number was $num"
        break
    fi
done

read -p "Enter to exit."