#!/bin/bash

SOURCE_DIR=$1

if [ ! -d "$SOURCE_DIR" ]; then
    echo "Error: Directory '$SOURCE_DIR' does not exist."
    exit 1
fi

DIR_NAME=$(basename "$SOURCE_DIR")
BACKUP_NAME="${DIR_NAME}_backup.tar.gz"

tar -czf "$BACKUP_NAME" "$SOURCE_DIR"

echo "Backup created: $BACKUP_NAME"

