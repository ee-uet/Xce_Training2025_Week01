#!/bin/bash

# input from user
num=$1

if (($num % 2 == 0)); then
	echo "The number is even"
else
	echo "The number is odd"
fi
