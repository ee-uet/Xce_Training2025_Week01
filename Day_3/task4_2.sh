#!/bin/bash

#task4.2
touch logfile.log
echo "2025-08-25 alice login" > logfile.log
echo "2025-08-25 bob login" >> logfile.log
echo "2025-08-25 alice logout" >> logfile.log

total_lines=0
while IFS= read -r line; do
    ((total_lines++))
done < logfile.log
echo "Total entries: $total_lines"

awk '{print $2}' logfile.log | sort | uniq

awk '{users[$2]++} END {for (user in users) print user ": " users[user]}' logfile.log

