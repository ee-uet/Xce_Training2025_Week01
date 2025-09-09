#!/bin/bash

file_name="input.txt"
Line_n=1

# Read file line by line and display with line numbers
while IFS= read -r line
do
	echo "$Line_n: $line"
	((Line_n++))
	
done < "$file_name"
