#!/bin/bash
count=1
while read -r  LINE; do
  count=$(( count + 1))
  echo "$count : $LINE" 
done < file.txt

