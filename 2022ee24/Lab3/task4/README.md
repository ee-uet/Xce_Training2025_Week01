
---

# Shell Scripting Exercises – Part 4

This repository contains solutions for three shell scripting exercises that focus on **file reading**, **text processing**, and **file backup** in Bash.

---

## Exercise 4.1: File Reading (Line Numbers)

### Problem

* Create a text file with several lines of content.
* Read the file line by line.
* Print each line prefixed with its line number.

### Approach

* Created a sample `file.txt` with 4 lines.
* Used a `while read` loop with an incrementing counter.
* Printed each line in the format: `line_number: content`.

### Example

```bash
$ ./t4_1.sh
1: 123456789
2: 987654321
3: abcdefghi
4: jklmnopqr
```

### Known Limitations

* File name is hardcoded (`file.txt`).
* Script overwrites the file each run.

---

## Exercise 4.2: Text Processing (Log Analysis)

### Problem

* Create a log file with entries of the format:

  ```
  YYYY-MM-DD username action
  ```
* Perform the following analysis:

  1. Count total number of entries.
  2. List unique usernames.
  3. Count actions per user (breakdown by type).

### Approach

* Created sample log file `system_log.txt` if not found.
* Used `wc -l` to count lines (total entries).
* Extracted usernames with `awk '{print $2}' | sort -u`.
* For each user:

  * Counted total actions with `grep -c`.
  * Counted per-action breakdown with `awk` + `uniq -c`.

### Example

```bash
$ ./t4_2.sh
=== LOG FILE ANALYSIS ===
File: system_log.txt

a. Total entries: 15

b. Unique users:
alice
bob
charlie
david

c. Actions per user:

User: alice
  Total actions: 6
  Action breakdown:
    file_download: 1
    file_upload: 1
    login: 2
    logout: 1
    system_reboot: 1
```

### Known Limitations

* Log format assumed fixed (3 fields).
* Usernames are case-sensitive.

---

## Exercise 4.3: File Backup (Compressed Archive)

### Problem

* Create a backup of a specified directory.
* Backup should be compressed (`tar.gz`).
* Backup file should include the current date in its name.
* Handle errors when directory doesn’t exist.

### Approach

* Checked for argument (`$1`) and validated directory existence.
* Constructed backup filename:

  ```
  <dir_name>_backup_<YYYYMMDD>.tar.gz
  ```
* Used `tar -czf` to create compressed archive.
* Printed confirmation and file size.

### Example

```bash
$ ./t4_3.sh my_folder
Creating backup of my_folder...
Backup created successfully: my_folder_backup_20250908.tar.gz
Size: 12K
```

### Known Limitations

* Only supports one directory at a time.
* Does not exclude temporary or hidden files.

---

## How to Run

1. Make scripts executable:

   ```bash
   chmod +x t4_1.sh
   chmod +x t4_2.sh
   chmod +x t4_3.sh
   ```

2. Run them:

   ```bash
   ./t4_1.sh
   ./t4_2.sh
   ./t4_3.sh <directory>
   ```

---

## What I Verified

* **Exercise 4.1:** Line numbers match file contents.
* **Exercise 4.2:** Entry counts, unique usernames, and per-user breakdown are correct.
* **Exercise 4.3:** Backup tarball is created with the correct name and size.

---

## Sources & AI Usage

* AI assistance was used for writing bash scripts and for structuring the README
* Verified functionality with sample inputs and directories.

---
