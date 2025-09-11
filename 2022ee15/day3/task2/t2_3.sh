#!/bin/bash
# RANDOM % 10 generates 0–9, +1 shifts to 1–10
sec=$((RANDOM % 10 + 1))

while true;
do
    read -p "Guess the number: " GUESS

    if [ "$GUESS" -eq "$sec" ]; then
        echo "Correct Guess!"
        break
    elif [ "$GUESS" -gt "$sec" ]; then
        echo "TOO HIGH"
    elif [ "$GUESS" -lt "$sec" ]; then
        echo "TOO LOW"
    fi
done

