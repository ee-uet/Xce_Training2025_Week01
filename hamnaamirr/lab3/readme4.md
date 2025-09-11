# Bash Script – Line Numbering from File

## Introduction
This script reads lines from a file (`file.txt`) and prints them with line numbers.  
It demonstrates how to use `while read` loops for file handling in bash.  

---

## Problem
- Read all lines from a text file.  
- Print each line with its corresponding line number.  

---

## Approach
- Initialize a counter `count=1`.  
- Use `while read -r LINE` to safely read each line (preserves spaces and special characters).  
- Increment the counter for each line.  
- Print the counter along with the line content.  
- Redirect input using `< file.txt`.  

---
## Example

2 : Hello
3 : World
4 : Bash Scripting

## AI usage
nope.

# Bash Script – User Action Logger

## Introduction
This script logs user actions into a file (`logs.log`) along with the current date and username.  
It demonstrates how to capture system information and append it to a log file.  

---

## Problem
- Record each action a user performs (given as an argument).  
- Include the current date and username.  
- Append the information to a log file for tracking.  

---

## Approach
- `date +"%Y-%m-%d"` captures the current date in `YYYY-MM-DD` format.  
- `whoami` retrieves the current username.  
- `$1` takes the first command-line argument (user action).  
- `>> logs.log` appends the record into the log file.  

---
## Example
2025-09-08 user logged in
2025-09-08 user created a file
2025-09-08 user deleted a file

## AI usage
- found whoami command using AI.

# Bash Script – Directory Backup

## Introduction
This script creates a compressed backup of a given directory.  
It ensures the directory exists before archiving it into a `.tar.gz` file.  

---

## Problem
- Accept a directory path as an argument.  
- Verify that the directory exists.  
- Create a compressed backup (`.tar.gz`) file.  
- Save the backup with a descriptive name.  

---

## Approach
- `$1` stores the directory path provided by the user.  
- `[ ! -d "$SOURCE_DIR" ]` checks if the directory exists; exits with an error if not.  
- `basename` extracts the directory name from the path.  
- The backup file name is formed as `dirname_backup.tar.gz`.  
- `tar -czf` compresses the directory into `.tar.gz` format.  
- The script prints a confirmation message with the backup file name.  

---

## Example
$ ./backup.sh my_project
Backup created: my_project_backup.tar.gz

## AI usage
- found how to use tar.

