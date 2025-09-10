#!/bin/bash

# Exercise 2.2: For Loop
# Fixed: Changed from while loop to for loop as required by exercise

if [ $# -ne 1 ]; then
    echo "Usage: $0 <number>"
    exit 1
fi

echo "First 10 multiples of $1:"
for count in {1..10}
do
    echo "$(($1 * $count))"
done