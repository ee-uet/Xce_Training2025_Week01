#!/bin/bash
# Create a compressed tar backup of a specified directory with today's date

read -p "Enter the path of directory: " target

# test -d checks directory existence; quote variables to handle spaces
if [ ! -d "$target" ]; then
    echo "${target} is not found"
    exit 1
fi

curr_date=$(date +%Y-%m-%d)
backup_file="${target}_backup_${curr_date}.tar.gz"

# tar -czf creates compressed archive
tar -czf "$backup_file" "$target"

echo "Backup created : ${backup_file}"

