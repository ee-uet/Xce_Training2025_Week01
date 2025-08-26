#!/bin/bash
if [ $(($1 % 2)) -eq 0 ]; 
then
    echo "entered number $1 is even"
else
    echo "entered number $1 is odd"
fi
