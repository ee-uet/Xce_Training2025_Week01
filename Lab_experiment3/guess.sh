#!/bin/bash
arg=$1
num=$(( (RANDOM % 10) + 1))
while [ $arg -ne $num ]
do
	read -p "enter guess again " arg
	if [ $((arg - num)) -gt 0 ]; then
		if [ $((arg - num)) -gt 5 ]; then
			echo "higher"
		else
			echo "close bit higher"
		fi
	elif [ $((num - arg)) -gt 5 ]; then
		echo "lower"
	else
		echo "close bit lower"
	fi
done
echo "guessed"
