#!/bin/bash
file="logfile.txt"

echo "Total number of entries:"
wc -l < "$file"

echo "Unique usernames:"
cut -d' ' -f2 "$file" | sort | uniq

echo "Actions per user:"
cut -d' ' -f2 "$file" | sort | uniq -c

