#!/bin/bash

file_name="backup.txt"
touch $file_name
current_date=$(date +%d-%m-%y)

read -p "Enter the Directory name: " dir

if [ ! -d "$dir" ]; then
    echo "Error! Directory Doesn't Exist"
else
    backup_name="backup_${current_date}.tar.gz"

    tar -czf "$backup_name" "$dir"
    echo "Backup Succesfully Created!"
fi

