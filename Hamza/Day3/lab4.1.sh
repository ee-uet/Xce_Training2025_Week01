#!/bin/bash
echo "Suno, ab 'file_to_read.txt' padhte hain..."
echo "Pehli line" > file_to_read.txt
echo "Dusri line" >> file_to_read.txt
echo "Teesri line" >> file_to_read.txt
i=1
while read line
do
    echo "Line $i: $line"
    i=$((i+1))
done < file_to_read.txt

echo "Pura ho gaya!"