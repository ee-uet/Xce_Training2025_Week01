#!/bin/bash

# Step 1: Take directory name from user
echo "Enter the directory you want to back up:"
read dir_to_backup

# Step 2: Check if directory exists
if [ ! -d "$dir_to_backup" ]; then #-d checks if the directory exists or not
    echo "Error: Directory $dir_to_backup does not exist."
    exit 1 # script ends here with error code 1
fi

# Step 3: Get today’s date
today=$(date +%Y-%m-%d)

# Step 4: Make a copy of the directory
cp -r "$dir_to_backup" "${dir_to_backup}_backup_$today"

# Step 5: Compress the copied folder
tar -czf "${dir_to_backup}_backup_$today.tar.gz" "${dir_to_backup}_backup_$today"
# -c: tells tar to create archive
# -z: compress (makes zip)
# -f: name of the file to create
# tar collects multiple files/folders and stores them in a single file.

# Step 6: Remove the extra copied folder (keep only the tar.gz file)
rm -r "${dir_to_backup}_backup_$today"

echo "Backup created: ${dir_to_backup}_backup_$today.tar.gz"


