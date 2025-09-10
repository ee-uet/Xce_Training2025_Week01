#!/bin/bash

# Check if a file argument is provided
if [[ $# -ne 1 ]]; then     # $# is the number of arguments
    echo "Usage: $0 <file>" >&2
    exit 1
fi

# Input file
file="$1"

# Check if file exists
if [[ ! -f "$file" ]]; then     # -f checks if it's a regular file
    echo "Error: File '$file' does not exist" >&2
    exit 1
fi

# Create backup with timestamp
timestamp=$(date +%Y%m%d_%H%M%S)        # Current date and time
backup_file="${file%.*}_backup_$timestamp.${file##*.}"  # Insert timestamp before file extension 
cp "$file" "$backup_file"
echo "Created backup: $backup_file"