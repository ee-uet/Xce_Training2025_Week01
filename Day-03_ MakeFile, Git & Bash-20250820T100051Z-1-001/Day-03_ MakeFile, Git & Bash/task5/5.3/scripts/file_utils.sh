#!/bin/bash
# File utility functions

backup_file() {
    local file=$1
    if [ -f "$file" ]; then
        cp "$file" "${file}.bak.$(date +%Y%m%d_%H%M%S)"
        echo "Backup created for $file"
    else
        echo "Error: File $file not found"
        return 1
    fi
}

count_lines() {
    local file=$1
    if [ -f "$file" ]; then
        wc -l < "$file"
    else
        echo "Error: File $file not found"
        return 1
    fi
}

# Main execution
case $1 in
    "backup")
        backup_file "$2"
        ;;
    "count")
        count_lines "$2"
        ;;
    *)
        echo "Usage: $0 <backup|count> <filename>"
        exit 1
        ;;
esac