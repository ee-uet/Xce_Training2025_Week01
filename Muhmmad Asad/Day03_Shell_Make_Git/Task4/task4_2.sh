#!/bin/bash
echo "2025-08-20 user_A login
2025-08-20 user_B logout
2025-08-20 user_C login
2025-08-21 user_A upload
2025-08-21 user_B download
2025-08-21 user_A logout" > log.txt

entries=&(wc -l < "log.txt")
echo "Total entries = $entries"

echo "Unique user names:"
awk '{print $2}' "log.txt" | sort | uniq 

echo "Actions per user:"
awk '{print $2}' "log.txt" | sort | uniq -c