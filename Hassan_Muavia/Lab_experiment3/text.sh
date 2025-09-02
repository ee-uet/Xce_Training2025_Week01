#!/bin/bash

line_num=1
while IFS= read -r line
do
    echo "$line_num: $line"
        line_num=$((line_num + 1))
        done < file.txt

