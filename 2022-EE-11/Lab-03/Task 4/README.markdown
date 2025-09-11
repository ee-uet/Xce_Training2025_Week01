# Bash Script: File Processing, Log Analysis, and Directory Backup

## Problem
This Bash script performs three tasks: reads a text file with line numbers, analyzes a log file for user actions, and creates a compressed backup of a directory.

## Approach
The script is organized into three main functions:
- **Read File with Numbers**: Displays a text file's contents with line numbers.
- **Log Analysis**: Processes a log file to count entries, list unique users, and summarize actions.
- **Backup Directory**: Creates a compressed tarball of a directory with timestamped filename and lists contents.

## Walkthrough
1. **Sample Text File Creation**:
   - Creates `sample_text.txt` using a here-document (`cat > ... << EOF`).
   - Contains five lines of sample text.
2. **Read File with Numbers**:
   - `read_file_with_numbers` checks if the file exists (`[[ ! -f "$filename" ]]`).
   - Reads lines using `while IFS= read -r line`, preserving whitespace.
   - Prints each line with a line number using `printf "%3d: %s\n"`.
3. **Sample Log File Creation**:
   - Creates `sample_log.txt` with timestamped user actions (e.g., login, upload).
4. **Log Analysis**:
   - `analyze_log` checks if the log file exists.
   - Counts total lines with `wc -l`.
   - Lists unique usernames with `awk '{print $2}' | sort -u | nl`.
   - Counts actions per user with `awk '{print $2}' | sort | uniq -c`.
   - Summarizes action types with `awk '{print $3}' | sort | uniq -c`.
5. **Directory Backup**:
   - Creates a test directory (`test_backup_dir`) with sample files and a subdirectory.
   - `backup_directory` checks if the source directory exists.
   - Generates a timestamped filename (`date +"%Y%m%d_%H%M%S"`).
   - Creates a `.tar.gz` archive using `tar -czf`.
   - Displays the backup size (`du -h`) and lists up to 10 files (`tar -tzf`).
6. **Cleanup** (commented out):
   - `cleanup_files` removes created files and directories.

## How to Run
1. **Prerequisites**: Requires a Unix-like environment (e.g., Linux, macOS, WSL) with Bash.
2. **Save the Script**: Save as `script.sh`.
3. **Make Executable**: Run:
   ```bash
   chmod +x script.sh
   ```
4. **Execute**: Run the script:
   ```bash
   ./script.sh
   ```
5. **Output**: The script creates files, processes them, and displays results. No user input is required. Uncomment `cleanup_files` to remove generated files.

## Examples
### Sample Run
```bash
$ chmod +x script.sh
$ ./script.sh
Created sample file: sample_text.txt
Reading file line by line with line numbers:
  1: This is line one of our sample file.
  2: Here we have the second line with some content.
  3: The third line contains different information.
  4: Line four has more text for processing.
  5: Finally, this is the fifth and last line.

Created log file: sample_log.txt
Log Analysis Results:
Total log entries: 12

Unique usernames:
     1	 alice
     2	 bob
     3	 charlie
     4	 david

Actions per user:
alice     : 4 actions
bob       : 3 actions
charlie   : 2 actions
david     : 2 actions

Action breakdown:
delete    : 1 times
download  : 2 times
login     : 4 times
logout    : 2 times
upload    : 3 times

Created test directory: test_backup_dir
Testing backup function:
Creating backup of 'test_backup_dir'...
Backup file: test_backup_20250908_125900.tar.gz
Success! Backup created: test_backup_20250908_125900.tar.gz (Size: 4.0K)
Backup contains:
test_backup_dir/
test_backup_dir/file1.txt
test_backup_dir/file2.txt
test_backup_dir/subdir/
test_backup_dir/subdir/nested.txt

Testing error handling with non-existent directory:
Error: Directory 'non_existent_dir' does not exist!
```

## Syntactical Shorthands Explained
- `#!/bin/bash`: Shebang specifying Bash as the interpreter.
- `cat > "$file" << EOF ... EOF`: Here-document to create a file with predefined content.
- `[[ ! -f "$filename" ]]`: Tests if a file does not exist (`-f` checks for file existence).
- `while IFS= read -r line`: Reads lines from a file, preserving whitespace (`IFS=`), and preventing backslash escaping (`-r`).
- `printf "%3d: %s\n" "$line_num" "$line"`: Formats output with a 3-digit line number and the line content.
- `wc -l < "$file"`: Counts lines in a file.
- `awk '{print $2}'`: Extracts the second field (username) from each line.
- `sort -u | nl`: Sorts unique lines (`-u`) and numbers them (`nl`).
- `uniq -c`: Counts occurrences of each unique line.
- `read count user`: Reads two values from `uniq -c` output into variables.
- `tar -czf "$filename" -C "$(dirname "$source_dir")" "$(basename "$source_dir")"`: Creates a compressed tarball, changing to the parent directory (`-C`) and archiving the directory.
- `du -h | cut -f1`: Gets the human-readable file size.
- `tar -tzf | head -10`: Lists up to 10 files in the tarball.
- `${2:-backup}`: Uses `backup` as the default base name if `$2` is unset.
- `date +"%Y%m%d_%H%M%S"`: Formats the current date and time (e.g., `20250908_125900`).
- `echo`: Outputs text or variables; standalone `echo` adds a blank line.