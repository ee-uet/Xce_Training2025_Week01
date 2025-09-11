#!/bin/bash

touch file.txt
echo "123456789" > file.txt
echo "987654321" >> file.txt
echo "abcdefghi" >> file.txt
echo "jklmnopqr" >> file.txt

line_number=1
while IFS= read -r line; do
    echo "$line_number: $line"
    ((line_number++))
done < "file.txt"