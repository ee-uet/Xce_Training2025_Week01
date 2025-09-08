#!/bin/bash
# Simple log analysis: count lines, list unique users, count entries per user
file_log="user.log"

# wc -l reads number of lines
total_enteries=$(wc -l < "$file_log")
echo "Total Entries: ${total_enteries}"

echo "Unique usernames:"
# assume username is second whitespace-separated field
cut -d' ' -f2 "$file_log" | sort | uniq

echo "Action Performs per User"
# count occurrences per username
cut -d' ' -f2 "$file_log" | sort | uniq -c | while read count user; do
    echo "${user} : ${count}"
done

