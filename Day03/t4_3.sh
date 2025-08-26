#!/bin/bash

# Simple Backup Script

# Check if directory is provided
if [ $# -eq 0 ]; then
    echo "Error: Please specify a directory to backup"
    echo "Usage: $0 <directory>"
    exit 1
fi

TARGET_DIR="$1"

# Check if directory exists
if [ ! -d "$TARGET_DIR" ]; then
    echo "Error: Directory '$TARGET_DIR' does not exist!"
    exit 1
fi

# Create backup filename with date
BACKUP_FILE="$(basename "$TARGET_DIR")_backup_$(date +%Y%m%d).tar.gz"

# Create compressed backup
echo "Creating backup of $TARGET_DIR..."
if tar -czf "$BACKUP_FILE" "$TARGET_DIR" 2>/dev/null; then
    echo "Backup created successfully: $BACKUP_FILE"
    echo "Size: $(du -h "$BACKUP_FILE" | cut -f1)"
else
    echo "Error: Failed to create backup!"
    exit 1
fi