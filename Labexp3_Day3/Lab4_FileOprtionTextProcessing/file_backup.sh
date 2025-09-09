#!/bin/bash

# Get directory path from user
read -p "Enter the directory path: " dir

# Check if directory exists
if [ ! -d "$dir" ]; then
	echo "No such directory exist"
	exit 1
fi 

# Generate date for backup filename
date=$(date +%F)
backup_name="$(basename "$dir")_$date.tar.gz"

# Create compressed tar backup
tar -czf "$backup_name" "$dir"

# Check if backup was successful
if [ $? -eq 0 ]; then
    	echo "Backup successful: $backup_name"
else
    	echo "Error: Backup failed."
    	exit 1
fi
