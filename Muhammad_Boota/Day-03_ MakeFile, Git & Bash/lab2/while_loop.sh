#!/bin/bash
rand=$(((RANDOM % 100)+1))
read -p "Guess the number: " guess
while [ $rand -ne $guess ]; do
  if [ $guess -ge $rand ];then
    echo "to high"
  else
    echo "to low"
  fi
  read -p "Guess the number: " guess
done
echo "guess is correct"