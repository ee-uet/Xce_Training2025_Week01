#!/bin/bash
 num=$1

 

num1=$((num%2))

 if [ $num1 -eq 0 ] 
 then
    echo "Number is even"
 else 
    echo "Number is Odd"
 fi