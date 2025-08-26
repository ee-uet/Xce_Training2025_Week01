#!/bin/bash

# Script: backup.sh
# Purpose: Backup a specified directory into a compressed tar file with current date

# Directory to backup (pass as argument)
DIR_TO_BACKUP=$1

# Check if directory argument is provided
if [ -z "$DIR_TO_BACKUP" ]; then
    echo "Error: Please provide a directory to backup."
    echo "Usage: $0 /path/to/directory"
    exit 1
fi

# Check if directory exists
if [ ! -d "$DIR_TO_BACKUP" ]; then
    echo "Error: Directory '$DIR_TO_BACKUP' does not exist."
    exit 1
fi

# Create backup file name with current date
BACKUP_FILE="backup_$(basename $DIR_TO_BACKUP)_$(date +%Y-%m-%d).tar.gz"

# Create compressed tar backup
tar -czf "$BACKUP_FILE" "$DIR_TO_BACKUP"

# Success message
echo "Backup of '$DIR_TO_BACKUP' completed successfully: $BACKUP_FILE"

