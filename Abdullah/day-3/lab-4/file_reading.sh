#!/bin/bash

# Exercise 4.1: File Reading
echo "Hello, My Name is Muhammad Abdullah." > output.txt
echo "I'm a student in my Senior Year." >> output.txt
echo "I'm excited that I'm about to be graduated in next 8 months." >> output.txt
echo "Thanks!!!" >> output.txt

file_name="output.txt"
line_number=1

if [ -f "$file_name" ]; then
    echo "File Processing Started!"

    while IFS= read -r line ;       # Read file line by line
    do                              # IFS = Internal Field Separator
        echo "Line $line_number: $line"
        ((line_number++))
    done < "$file_name"             # Redirect file to while loop
else
    echo "Error: File $file_name not found!"
fi