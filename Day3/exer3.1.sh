#!/bin/bash
factorial(){
	num=$1
	fact=1
	for (( i=2; i<=$num; i++ ))
	do
		fact=$((fact*i))
	done
   	echo "$fact"         
}
factorial 1 
factorial 4
factorial 5
