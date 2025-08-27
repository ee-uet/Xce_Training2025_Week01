#!/bin/bash

factorial() {

	number=$1
	original=$number
	result=1

	if [ $number -lt 0 ]; then
		echo "Negative numbers do not have factorial"
	elif [[ $number -eq 0 || $number -eq 1 ]]; then 
		echo "The factorial of $original is 1"
	else
		while [ $number -ne 0 ]; do
			result=$((result * number))
			((number--))
		done

		echo "The factorial of $original is $result"
	fi
}

factorial 5
factorial 7
factorial 0
factorial 1
factorial -4
factorial 10
