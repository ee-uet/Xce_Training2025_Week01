#!/bin/bash
# $1 is the first command-line argument
if [ $(($1 % 2)) -eq 0 ]; then
    echo "Number is even"
else
    echo "Number is odd"
fi

