#!/bin/bash
# task1.1
echo "Hello World!"

# task1.2
read -p "Enter your Name:" Name
echo "Hello, $Name!"

#task1.3
echo "Enter 0th argument: $0"
echo "Enter 1st argument: $1"
echo "Enter 2nd argument: $2"
SUM=$(($1 + $2));
echo "SUM = $SUM"
