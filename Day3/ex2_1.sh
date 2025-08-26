#!/bin/bash


if [ $(($1 % 2)) == 0 ]; then
    echo "your number is EVEN"
else 
    echo "Your number is not even"
fi
