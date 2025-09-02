#!/bin/bash
dir=$1

if [ ! -d "$dir" ]; then
    echo "Error: Directory '$dir' does not exist!"
        exit 1
        fi


        date_str=$(date +%F)

        backup_name="$(basename "$dir")_$date_str.tar.gz"

        tar -czf "$backup_name" "$dir"
        echo "Backup created: $backup_name"

