#!/bin/bash

src_dir=$1

if [ -z "$src_dir" ]; then
    echo "No directory provided "
    exit 1
fi

if [ ! -d "$src_dir" ]; then
    echo "The given directory is not found "
    exit 1
fi

backup_name="$(basename "$src_dir")_backup_$(date +%Y-%m-%d).tar.gz"

tar -czf "$backup_name" "$src_dir"
echo "Beakup created: $backup_name"


