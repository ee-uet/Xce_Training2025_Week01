#!/bin/bash

echo "Hello, My Name is Muhammad Abdullah." > output.txt
echo "I'm a student in my Senior Year." >> output.txt
echo "I'm hapy that I'm about to be gradeted in next 10 months." >> output.txt
echo "Thanks!!!" >> output.txt

file_name="output.txt"
line_number=1
if [ -f "$file_name" ]; then
    echo "File Processing Started!"

    while IFS= read -r line ;
    do
        echo "Line $line_number:  $line"
        ((line_number++))
    done <"output.txt"

fi

