#!/bin/bash
RND_VALUE=$((RANDOM % 10 + 1))
CHECK=1
while [ $CHECK -eq 1 ];
do
	read -p "enter the value: "  USR_VALUE
	if [ $USR_VALUE -eq $RND_VALUE ]; then
		echo "you entered correct value: "
		CHECK=0
	elif [ $USR_VALUE -gt $RND_VALUE ];  then
		echo "entered value is greater:"
	else
		echo "entered value is lower: "
	fi
done
