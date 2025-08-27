#!/bin/bash

# total entries
i=$(wc -l < file.log)
echo "Total entries are: $i"

# unique usernames
echo "Unique usernames are:"
awk '{print $2}' file.log | sort | uniq

# count actions per user
echo "Actions per user:"
awk '{print $2}' file.log | sort | uniq -c





