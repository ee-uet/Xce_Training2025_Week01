#!/bin/bash
echo -n "Enter a number to check whether its odd or even: "
read num

if (( num % 2 == 0));then
   echo "$num is Even"
else
   echo "$num is Odd"
fi

echo -n "Enter a number to find its 1st 10 multiples: "
read num

for i in {1..10}
do
   echo "$((num*i))"
done

random_number=$((RANDOM % 11))
guess=0
while [ $guess -ne $random_number ]
do
  read -p "Guess a number between 1 and 10 : " guess
  if [ $guess -lt $random_number ]; then
     echo "Give a Higher Number"
  elif [ $guess -gt $random_number ]; then
     echo "Give a Lower Number"
  else
     echo "Correct"
  fi
done
