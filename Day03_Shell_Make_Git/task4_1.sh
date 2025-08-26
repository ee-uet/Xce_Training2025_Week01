#!/bin/bash
echo "Hello World" > data.txt
echo "This is line number 2" >> data.txt
echo "This is line number 3" >> data.txt

line_no=1
while IFS= read -r fruit; do
    echo "$line_no: $fruit"
    ((line_no++))
done < "data.txt"