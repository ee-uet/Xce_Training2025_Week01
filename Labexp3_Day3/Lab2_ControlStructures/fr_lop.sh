#!/bin/bash

# Exercise 2.2: For Loop - Multiplication Table
# Loop from 1 to 10 to generate multiplication table
for ((i = 1; i <= 10; i++))
do 
	echo "$i multiple of $1 is $(( $1 * i))" 
done
