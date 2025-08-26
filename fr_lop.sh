#!/bin/bash
for ((i = 1; i <= 10; i++))
do 
	echo "$i multiple of $1 is $(( $1 * i))" 
done
