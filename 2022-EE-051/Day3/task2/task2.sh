#!/bin/bash

# Exercise 1
# takes a number from user
echo -n "Enter a number to check whether its odd or even: "
read num

# tells if the number is even or odd
if (( num % 2 == 0));then
   echo "$num is Even"
else
   echo "$num is Odd"
fi

# Exercise 2
# takes a number fom user
echo -n "Enter a number to find its 1st 10 multiples: "
read num

# find and prints its first 10 multiples
for i in {1..10}
do
   echo "$((num*i))"
done

# Exercise 3 
# generates random numbers between 1 and 10
random_number=$((RANDOM % 11))
guess=0

# uses a while loop to allow the user to guess until correct
while [ $guess -ne $random_number ]
do
  read -p "Guess a number between 1 and 10 : " guess

  # provides "higher" or "lower" hints
  if [ $guess -lt $random_number ]; then
     echo "Give a Higher Number"
  elif [ $guess -gt $random_number ]; then
     echo "Give a Lower Number"
  else
     echo "Correct"
  fi
done
