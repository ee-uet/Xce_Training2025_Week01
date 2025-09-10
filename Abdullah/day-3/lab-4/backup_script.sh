#!/bin/bash

# Exercise 4.3: File Backup
current_date=$(date +%Y-%m-%d)

read -p "Enter the Directory name: " dir

if [ ! -d "$dir" ]; then        # Check if directory exists
    echo "Error! Directory '$dir' doesn't exist"
    exit 1                      # Exit with error code
else
    backup_name="backup_${current_date}.tar.gz"

    if tar -czf "$backup_name" "$dir"; then # -czf: create, gzip, file
        echo "Backup successfully created: $backup_name"
    else
        echo "Error: Failed to create backup"
        exit 1
    fi
fi