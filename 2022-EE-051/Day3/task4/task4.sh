#!/bin/bash

# Exercise 1
# a script that reads text_file.txt file line by line
filename="text_file.txt"
n=1

# print each line prefixed with its line number
while read -r line; do
    echo "$n: $line"
	n=$((n+1))
done < "$filename"

# Exercise 2
file="log.txt"

# Counts the total number of entries
echo "Total entries: $(wc -l < $file)"

#Lists unique usernames
echo "Unique users:"
cut -d' ' -f2 $file | sort | uniq

#Counts actions per user
echo "Actions per user:"
cut -d' ' -f2 $file | sort | uniq -c

# Exercise 3
# a script that creates a backup of a specified directory
src_dir="$1"


if [ ! -d "$src_dir" ]; then
    echo "Error: Directory '$src_dir' does not exist."
    exit 1
fi

#  compressed tar file with the current date in its name
date_str=$(date +%F)
backup_file="${src_dir##*/}_backup_${date_str}.tar.gz"
tar -czf "$backup_file" -C "$src_dir" .

# error handling for cases where the directory doesn't exist
if [ $? -eq 0 ]; then
    echo "Backup created successfully: $backup_file"
else
    echo "Error: Backup failed."
    exit 1
fi


