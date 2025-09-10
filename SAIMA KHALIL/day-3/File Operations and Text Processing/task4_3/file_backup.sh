#!/bin/bash 
create_backup() {
    local dir_to_backup=$1
    local backup_dir=$2
    local current_date=$(date +%Y-%m-%d)
    local backup_file="${backup_dir}/backup_${current_date}.tar.gz"

    # Check if the directory to backup exists
    if [[ ! -d $dir_to_backup ]]; then # -d checks if the directory exists
        echo "Error: Directory $dir_to_backup does not exist."
        return 1
    fi
 
    # Create the backup directory if it doesn't exist
    mkdir -p "$backup_dir"

    # Create a compressed tar file of the specified directory
    tar -czf "$backup_file" -C "$dir_to_backup" .
    # -c :create a new archive -z:compress using gzip -f:  filename of the archive
    #-C yni change directory before adding files Matlab tar, $dir_to_backup me switch karega a

    if [[ $? -eq 0 ]]; then
        echo "Backup of $dir_to_backup created successfully at $backup_file"
    else
        echo "Error: Failed to create backup."
        return 1
    fi
}

# Main script execution
SOURCE_DIR="/mnt/c/Users/Hp/Desktop/XCELERIUM/LAB03/File Operations and Text Processing"
BACKUP_DIR="/mnt/c/Users/Hp/Desktop/XCELERIUM/LAB03/backup"

create_backup "$SOURCE_DIR" "$BACKUP_DIR"
