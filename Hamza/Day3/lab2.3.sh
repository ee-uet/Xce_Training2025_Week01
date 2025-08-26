#!/bin/bash
randomNumber=$((RANDOM % 10 + 1))
guess=0

echo "Ek number socha hai 1 se 10 ke beech. Guess karo!"

while [ $guess -ne $randomNumber ]; do
    read -p "Tumhara guess kya hai? " guess
    if [ $guess -lt $randomNumber ]; then
        echo "Arey bhai, thoda aur ucha! Higher!"
    elif [ $guess -gt $randomNumber ]; then
        echo "Zyada ho gaya! Thoda neeche! Lower!"
    fi
done

echo "Sahi jawab! ap ne toh kamaal kar diya!"
