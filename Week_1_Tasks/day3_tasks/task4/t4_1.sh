#!/bin/bash

file="sample.txt"
line_num=1

while IFS= read -r line;
do
    echo "${line_num}: ${line}"
    ((line_num++))
done < "$file"
