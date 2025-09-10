#!/bin/bash

# Exercise 4.2: Text Processing
file_name="date_file.log"

cat > "$file_name" << EOF   # puts the following lines into date_file.log
2021-01-31 abdul101 login
2021-02-28 abdul102 login
2021-03-31 abdul102 log_off
2021-04-30 abdul104 login
2021-05-31 abdul102 terminate
2021-06-30 abdul101 terminate
EOF

total_count=$(wc -l < "$file_name") #wc -l counts the number of lines in the file
echo "Total Entries: $total_count" 

echo "Unique Usernames:"
awk '{print $2}' "$file_name" | sort | uniq  # Extract and list unique usernames

echo "Action Count per User:"
# awk to count actions per user and print the result
awk '{count[$2]++} END {for (user in count) print user, count[user]}' "$file_name"