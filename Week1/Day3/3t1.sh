#!/bin/bash
echo "Hello, World!"

echo "Enter your name: "
read name
echo "Hello, $name! Welcome to Shell Scripting."

if [ $# -ne 2 ]; then
    echo "Usage: $0 num1 num2"
	exit 1
fi

sum=$(($1 + $2))
echo "Sum = $sum"
