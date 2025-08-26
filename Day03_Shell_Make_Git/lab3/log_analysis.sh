#!/bin/bash
file="log.txt"

echo "total number of entries are $(wc -l < "$file")"
echo "unique user names"
cut -d' ' -f2 "$file" | sort -u
echo "actions per user"
cut -d' ' -f2 "$file" | sort | uniq -c
