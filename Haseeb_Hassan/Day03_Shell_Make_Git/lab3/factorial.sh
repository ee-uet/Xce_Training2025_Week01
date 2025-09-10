#!/bin/bash
factorial(){
	num=$1
	result=1
	for((i=1;i<=num;i++))
	do
		result=$((result*i))
	done
	echo $result

}
echo "factorial of 5 is $(factorial 5)"
echo "factorial of 7 is $(factorial 7)"
