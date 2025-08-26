#!/bin/bash

count=1
fact=1
result=0
read -p "Enter number to know its factorial:" NUM
echo ""The factorial of $NUM is $factorial("$NUM")"

function factorial($NUM) {
    for [ count=1; count<=NUM; count++ ]
         result=$((result*count))
}   
echo "$result"