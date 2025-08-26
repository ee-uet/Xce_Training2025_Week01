#!/bin/bash

create_backup() {
    local file=$1
    if [ -f "$file" ]; then
        cp "$file" "${file}.bak"
        echo "Backup created: ${file}.bak"
    else
        echo "Error: File $file does not exist" >&2
        return 1
    fi
}