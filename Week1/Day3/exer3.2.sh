#!/bin/bash
arr=("apple" "banana" "mango" "kiwi")
size=${#arr[@]}
for (( i=0; i<size; i++ ))
do 
	echo "${arr[i]}"
done

arr+=("orange")
arr+=("dragonfruit")
size=${#arr[@]}
echo "After adding more fruits in array"
for (( i=0; i<size; i++ ))
do
        echo "${arr[i]}"
done

