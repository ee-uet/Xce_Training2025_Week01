# Directory Backup Script

## Problem
Create a Bash script to back up a specified directory:
- Takes a directory path as input.
- Compresses the directory into a `.tar.gz` archive.
- Names the backup with the directory name and current date.

## Approach
1. Accept the directory path as a command-line argument (`$1`).
2. Check if the argument is provided; if not, print an error and exit.
3. Verify that the provided path exists and is a directory; otherwise, print an error and exit.
4. Generate a backup filename using the format:
<directory_name>backup<YYYY-MM-DD>.tar.gz
5. Use `tar -czf` to create a compressed archive of the directory.
6. Print a message showing the backup filename.

## How to Run
1. Save the script as `E4_3.sh`.
2. Make it executable:
```bash
chmod +x E4_3.sh
./E4_3.sh /path/to/source_directory
./E4_3.sh /home/hafiz/Documents/X_training/C/DAY_3/Lab_4/Exercise_3/abc

## Example Run
./backup_dir.sh /home/user/Documents


Output:

Backup created: Documents_backup_2025-09-07.tar.gz

## Known Limitations

Script does not handle spaces in directory names robustly unless quoted.

Does not check for existing backup files with the same name; may overwrite them.

Only works on Unix-like systems with tar installed.

## Sources & AI Usage

This Bash backup script was AI-assisted (ChatGPT). I learned how to:

Use command-line arguments ($1) in Bash scripts.

Check if a directory exists (-d) and handle errors.

Generate a dynamic backup file name using basename and date.

Use tar with options -czf to create compressed backups.

All code was manually implemented and tested.

## What I Verified

I tested the script on different scenarios:

Valid directory → backup file created successfully.

Non-existing directory → prints an error and exits.

No argument provided → prints error and exits.

Backup file naming → confirmed it includes the directory name and current date correctly.