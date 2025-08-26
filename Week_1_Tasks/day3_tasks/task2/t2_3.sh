#!/bin/bash

sec=$((RANDOM % 10 + 1))

while true;
do
read -p "Guess the number: " GUESS
if [ $GUESS -eq $sec ];
then 
echo "Write Guess"
break
elif [ $GUESS -gt $sec ]
then
echo "TOO HIGH"
elif [ $GUESS -lt $sec ]
then
echo "TOO LOW"
fi
done