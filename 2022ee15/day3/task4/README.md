
## Problem
- **t4_1:** Read a text file line-by-line and print each line prefixed with its line number.  
- **t4_2:** Analyze a log file of format `YYYY-MM-DD username action`:
  - Count total entries
  - List unique usernames
  - Count actions per user  
- **t4_3:** Create a backup script that compresses a specified directory into a tar.gz named with the current date, and handle the case where the directory does not exist.

## Approach
- Use `read -r` + `while` loop for safe, line-preserving file reading (`t4_1`).  
- Use `wc -l`, `cut`, `sort`, `uniq` and `uniq -c` for log summarization (`t4_2`). Assumes username is the 2nd space-separated field.  
- Check directory existence with `[ -d ]`, build a date-stamped filename, and create a compressed tarball with `tar -czf` (`t4_3`). Quote variables where needed to handle spaces.

## How to Run
1. **Make executable:**
   ```bash
   chmod +x t4_1.sh t4_2.sh t4_3.sh
2. **Prepare input files:**
    For t4_1 create sample.txt with several lines.
    For t4_2 create user.log with lines like:
    2025-08-22 Ali login
    2025-08-21 Ali Create Repo
    ...
3. **Run scripts:**
Read file: 
    ./t4_1
Log analysis: 
    ./t4_2
Backup:
    ./t4_3 

## Test Cases
t4_1
    Create sample.txt:
    Line one
    Line two
    Line three
Run:
$ ./t4_1
    1: Line one
    2: Line two
    3: Line three

t4_2
    Create user.log:
    2025-08-22 Ali login
    2025-08-21 Ali Create Repo
    2025-08-21 Abdullah login
    2025-08-22 Abdullah logout
    2025-08-21 Bilal upload
    2025-08-22 Ali logout
Run:
$ ./t4_2
    Total Entries: 6
    Unique usernames:
    Abdullah
    Ali
    Bilal
    Action Performs per User
    Abdullah : 2
    Ali : 3
    Bilal : 1

t4_3
Run and enter a valid directory path:
$ ./t4_3
    Enter the path of directory: /home/ali/training/day_3/task4/sample
    Backup created : //home/ali/training/day_3/task4/sample_backup_2025-09-07.tar.gz

## Known Limitations
1. t4_1 reads from sample.txt — change the file variable if your file has a different name.
2. t4_2 assumes log entries are space-separated and the username is the second field; different formats need adapting.
3. t4_3 does not check available disk space or confirm overwrite of an existing backup file with the same name.

## Sources & AI Usage
1. AI helped provide syntax for reading lines in a file.  
2. AI showed how to extract unique names in `t4_2`.  
3. AI suggested tar.gz compression syntax in `t4_3`.

## What I Verified
1. `t4_1` correctly reads lines with line numbers.  
2. `t4_2` counts entries, lists unique usernames, and shows action counts.  
3. `t4_3` successfully creates a dated tar.gz backup and handles missing directories.

