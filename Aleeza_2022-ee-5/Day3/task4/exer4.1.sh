#!/bin/bash

filename="file.txt"      
echo "Hello world!" > "$filename" #if doesn't exist already, > operator makes
echo "Hope you're good" >> "$filename" #adding line
echo "Nice to meet you" >> "$filename" #adding line
num=1 #no spaces allowed around =

cat "$filename" | while read -r line; do  #give file to while and read each line
    echo "$num: $line"  #print line and line number
    ((num++))  #increment line number
done
