#!/bin/bash

# Exercise 2.1: If-Else Statement
if [ $# -ne 1 ]; then
    echo "Usage: $0 <number>"
    exit 1
fi

if [ $(($1 % 2)) == 0 ]; then
    echo "your number is EVEN"
else 
    echo "Your number is not even"
fi