#!/bin/bash

filename="E4_1.txt"
line_no=1

while IFS= read -r line; do
    echo "$line_no : $line"
    ((line_no++))
done < "$filename"


