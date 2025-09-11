#!/bin/bash

# Exercise 1
# prints Hello, World!
echo "Hello, World!"

# Exercise 2
# takes the name fromthe user and prints a greeting statement
echo "Enter your name: "
read name
echo "Hello, $name! Welcome to Shell Scripting."

# Exercise 3
# tells how to run the program
if [ $# -ne 2 ]; then
    echo "Usage: $0 num1 num2"
	exit 1
fi

sum=$(($1 + $2))
echo "Sum = $sum"