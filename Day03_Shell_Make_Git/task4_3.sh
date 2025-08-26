#!/bin/bash

read -p "enter directory for you want back up: " dir

if [ ! -d "$dir" ]; then
    echo "error dir = $dir does'nt exist: "
    exit 1
fi
dirname=$(basename "$dir")
backup_file="${dirname}_backup_$(date +%F).tar.gz"
tar -czf "$backup_file" "$dir" 2>/dev/null
if [ $? -eq 0 ]; then
    echo "Backup successful: $backup_file"
else
    echo "Error: Backup failed"
    exit 1
fi