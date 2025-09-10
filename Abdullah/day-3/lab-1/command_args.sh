#!/bin/bash

# Exercise 1.3: Command-line Arguments

if [ $# -ne 2 ]; then           # Check if exactly two arguments are provided
    echo "Usage: $0 <number1> <number2>"    # Print usage message
    exit 1
fi

NUM1=$1
NUM2=$2

SUM=$((NUM1 + NUM2))
echo "The sum of $NUM1 and $NUM2 is: $SUM"