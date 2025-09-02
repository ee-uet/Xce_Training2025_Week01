#!/bin/bash
num=$1
if [ $((num % 2)) -eq 0 ]; then
	echo "number is even"
else
	echo "number is odd"
fi
