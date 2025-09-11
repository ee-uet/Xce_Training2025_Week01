#!/bin/bash
#task2.1
#if [ $(($1%2))==0 ]; then
#echo "Number is Even!"
#else
#echo "Number is Odd!"
#fi

#task 2.2
#for ((i=0; i<11; i++))
#do echo "$i multiple of $1 is: $(($1*$i))"
#done

#task2.3
random=$(( (RANDOM % 10)+1 ))
#echo "Random number between 1 and 10: $random"
read -p "Enter your guess: " guess
while [ $guess != $random ] 
do
read -p "Try again: " guess
if [ $guess -gt $random ]; then
    echo "Guessed number is high. Try lower"
elif [ $guess -lt $random ]; then
    echo "Guessed number is low. Try higher"
fi
done
echo "You guessed correctly!"