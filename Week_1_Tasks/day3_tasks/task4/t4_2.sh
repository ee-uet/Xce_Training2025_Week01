#!/bin/bash

file_log="user.log"

total_enteries=$(wc -l < $file_log)
echo "Total Entries: ${total_enteries}"

echo "Unique usernames:"
cut -d' ' -f2 "$file_log" | sort | uniq 

echo "Action Performs per User"
cut -d' ' -f2 "$file_log" | sort | uniq -c | while read count user; 
do
echo "${user} : ${count}"
done