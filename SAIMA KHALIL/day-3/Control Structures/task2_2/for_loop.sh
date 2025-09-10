#!/bin/bash
if [ "$#" -ne 1 ]; then
    echo "Provide exactly a number."
    exit 1
fi
number=$1
# Loop to calculate and print the first 10 multiples
for ((i=1;i<=10;i++)) 
do    
    multiple=$((number * i))
    echo "Multiple $i of $number is: $multiple"
done        

 