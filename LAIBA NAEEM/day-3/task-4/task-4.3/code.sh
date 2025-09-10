#!/bin/bash
read -p "Enter directory: " Directory

DATE=$(date +%F)

BACKUP_NAME="${Directory}_backup_$DATE.tar.gz"

tar -czf "$BACKUP_NAME" "$Directory"
if [[ -f "$BACKUP_NAME" ]]; then
    echo "Backup successful!"
else
    echo "Backup failed!"
fi


# /mnt/c/Users/123/Desktop/xcelerium