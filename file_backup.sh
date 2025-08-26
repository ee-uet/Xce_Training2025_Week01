#!/bin/bash

read -p "Enter the directory path: " dir

if [ ! -d "$dir" ]; then
	echo "No such directory exist"
	exit 1
fi 

date=$(date +%F)

backup_name="$(basename "$dir")_$date.tar.gz"

tar -czf "$backup_name" "$dir"

if [ $? -eq 0 ]; then
    	echo "Backup successful: $backup_name"
else
    	echo "Error: Backup failed."
    	exit 1
fi
