#!/bin/bash

NUM=$((RANDOM % 100 + 1))
GUESS=101
ATTEMPTS=0
while [ $NUM -ne $GUESS ]
do
    read -p "(Re)Enter guess: " GUESS
    ATTEMPTS=$((ATTEMPTS +1))

    if [ $GUESS -lt $NUM ]; then
        echo "lower"
    elif [ $GUESS -gt $NUM ]; then
        echo "higher!"
    fi

done
echo "You took $ATTEMPTS attempts to guess"
