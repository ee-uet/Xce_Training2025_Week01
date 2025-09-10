#!/bin/bash
if [ "$#" -ne 2 ]; then
    echo "Provide exactly two numbers as arguments." #bash no.of arg=$# , -ne=not equal
    exit 1 #stoping script execution
fi
num1=$1 
num2=$2
sum=$((num1 + num2))
echo "The sum of $num1 and $num2 is: $sum" 
