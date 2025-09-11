#!/bin/bash

filename="logfile.txt"

# Create a sample log file
echo "2025-02-27 aleeza login"  > "$filename"
echo "2025-02-16 zahra login"  >> "$filename"
echo "2025-02-10 saima logout" >> "$filename"
echo "2025-02-10 aleeza logout" >> "$filename"

# Count total entries
total=$(wc -l < "$filename")
echo "Total entries: $total"

# Print unique usernames
echo "Unique usernames:"
awk '{print $2}' "$filename" | sort | uniq

# Print how many times each user performed an action
echo "Actions per user:"
awk '{print $2}' "$filename" | sort | uniq -c

