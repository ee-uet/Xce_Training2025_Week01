#!/bin/bash

file_name="input.txt"
Line_n=1

while IFS= read -r line
do
	echo "$Line_n: $line"
	((Line_n++))
	
done < "$file_name"
