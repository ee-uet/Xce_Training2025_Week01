#!/bin/bash
# Read a file 
file="sample.txt"
line_num=1

# read -r prevents backslash escaping; IFS= keeps leading/trailing whitespace
while IFS= read -r line; do
    echo "${line_num}: ${line}"
    ((line_num++))
done < "$file"

