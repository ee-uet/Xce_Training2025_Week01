#!/bin/bash

dir=$1

if [ ! -d "$dir" ]; then
	echo "Directory doesn't exist, unable to create a backup file for this specific directory."
else
	date=$(date +%F)
	dirName=$(basename "$dir")
	backupName="backup_${dirName}_${date}.tar.gz"
	tar -czf "$backupName" "$dir"
	echo "Backup file created successfully"
fi
