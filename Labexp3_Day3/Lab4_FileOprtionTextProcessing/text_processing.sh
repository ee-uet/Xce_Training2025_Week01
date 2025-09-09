#!/bin/bash

file_name="log.txt"

# Count total number of entries in log file
total_entries=$(wc -l < "$file_name")
echo "Total number of entries are $total_entries"

echo "Unique user"
# Extract usernames (2nd column) and show unique ones
awk '{print $2}' "$file_name" | sort -u

echo "User actions"
# Count actions per user
awk '{print $2}' "$file_name" | sort | uniq -c
