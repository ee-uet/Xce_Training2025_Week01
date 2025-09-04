#!/bin/bash
directory="$1"
if [[ ! -d "$directory" ]]; then
    echo "Error: Directory '$directory' does not exist."
    exit 1
fi
backup_file="backup_$(date +%Y-%m-%d).tar.gz"
tar -czf "$backup_file" "$directory"

if [[ $? -eq 0 ]]; then
	echo "backup successfull $backup_file"
else
	echo "backup fail"
	exit 1
fi


