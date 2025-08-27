#!/bin/bash

# input from user
num=$1

# multiples of number
echo "Its multiples are: "
for ((i = 1; i <= 10; i++)); do
	echo "$((num*i))"
done
