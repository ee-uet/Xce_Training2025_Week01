#!/bin/bash

filename="E4_2.log"

echo "Total no of entries: "

wc -l < $filename
echo ""

echo "Unique Usernames: "
awk '{print $2}' "$filename" | sort | uniq 
echo ""

echo "Count action per username"
awk '{print $2}' "$filename" | sort | uniq -c | awk '{print $1, $2}'
echo ""
