#!/bin/sh
echo "Hello, World"
echo

read -p "Enter your name: " NAME
echo "Hello, $NAME!"
echo

read -p "Enter two numbers: " n1 n2
sum=$((n1 + n2))
echo "The sum is: $sum"
echo

read -p "Enter to exit."
