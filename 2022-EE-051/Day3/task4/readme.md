# Lab 4: File Operations and Text Processing in Bash

## Overview
This lab covers how to handle **files** and perform **text processing** in Bash.  
Key concepts include:
- Reading files line by line  
- Using text processing commands like `wc`, `cut`, `sort`, `uniq`  
- Automating file backup with error handling  

---
# Code Structure

- **Exercise 4.1: File Reading** → Script creates a text file, reads it line by line using a loop, and prints each line with its line number.  
- **Exercise 4.2: Text Processing** → Script processes a log file by counting total entries, listing unique usernames, and counting actions per user.  
- **Exercise 4.3: File Backup** → Script checks if a given directory exists, creates a compressed tar backup with the current date in its filename, and handles errors if the directory is missing.  

## How the Code Works

### Exercise 4.1 – File Reading

* Opens a file named **`text_file.txt`**.
* Reads each line using a **while loop**.
* Prints each line prefixed with its line number (`n: line`).

---

### Exercise 4.2 – Text Processing

* Uses a **log file** (`log.txt`) with format:

  ```
  YYYY-MM-DD username action
  ```
* Counts total entries with `wc -l`.
* Extracts unique usernames using `cut -d' ' -f2 | sort | uniq`.
* Counts actions per user with `cut | sort | uniq -c`.

---

### Exercise 4.3 – File Backup

* Takes a directory path as **argument**.
* Checks if directory exists; exits with error if not.
* Creates a compressed tarball (`.tar.gz`) named with the **current date**.
* Provides success/failure messages.

---

## How to Compile and Run

Bash scripts don’t require compilation. Just make the script executable.

1. Save the file as **`task4.sh`**
2. Open terminal in the script’s directory
3. Run the following commands:

```bash
# Give execute permission
chmod +x task4.sh

# Run the script
./task4.sh <directory_name>
```

---

## Example Run

```sh

 ./task4.sh mydata
1: ab
2: cd
3: ef
4: gh
5: ij
6: kl
7: mn
8: op
9: qr
10: st
11: uv
12: wx
13: yz
Total entries: 4
Unique users:
ali
sana
zahra
Actions per user:
      1 ali
      1 sana
      2 zahra
Backup created successfully: mydata_backup_2025-09-08.tar.gz

```
## Reference
- Slides
- AI