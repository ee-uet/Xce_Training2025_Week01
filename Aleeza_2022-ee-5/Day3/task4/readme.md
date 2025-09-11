# Lab 4: File Operations and Text Processing

# Exercise 4.1: File Reading
This Bash script creates a **text file** with several lines of content.  
It then reads the file **line by line** and prints each line, prefixed with its **line number**.  

---
##  Approach
- Create a text file and store initial text content inside the file using `>` and `>>` operators.   
- Use a `while` loop with `read -r` to read the file line by line.  
- Track line numbers with a counter variable.  
- Print each line with its corresponding line number.  

---

##  How to Run
1. Save the script as `exer4.1.sh`.  
2. Give it execute permission and run:
   ```bash
   chmod +x exer4.1.sh
   ./exer4.1.sh
   ```
## Commands Used

- `>` : creates a new file (or overwrites if it exists).
- `>>` : appends a line to the file.
- `cat "$filename"` : outputs file contents.
- `while read -r line` : reads the file line by line.
- `((num++))` : increments the line counter.

## Sources and AI usage

- AI help in how to write into a file and how to read a file line by line in Bash. - `ChatGPT`
 ---
 
# Exercise 4.2: Text Processing
This Bash script processes a **log file** containing entries in the format:  
`YYYY-MM-DD username action`.  

It performs three main tasks:  
1. Counts the total number of log entries.  
2. Lists unique usernames.  
3. Counts how many times each user performed an action.  

---

## Approach
- Create a sample log file with multiple entries.  
- `wc` means word count.
- Use `wc -l` to count the total number of lines (entries).  
- Extract usernames (2nd column) using `awk`, then sort and remove duplicates with `uniq`.  
- Use `uniq -c` with sorted usernames to count how many times each appears.  

---

## How to Run
1. Save the script as `exer4.2.sh`.  
2. Give it execute permission and run:
   ```bash
   chmod +x exer4.2.sh
   ./exer4.2.sh
   ```
## Sources and AI usage

- Asked `ChatGPT` how to extract specific columns from a file and count duplicates.
- Concepts learnt with help of AI (text processing in Bash, unique filtering).
- Final code review by AI.

---

# Exercise 4.3:  File Backup
This Bash script creates a **backup** of a specified directory.  
The backup is stored as **(.tar.gz)** file with the **current date** in its name.  

---

##  Approach
- Ask the user for the directory name.  
- Check if the directory exists (`-d` flag). If not, exit with an error.  
- Get the current date using the `date` command.  
- Copy the directory (to avoid directly compressing the original).  
- Compress the copy using `tar -czf`.  
- Delete the extra copied folder (only keep `.tar.gz`).  
- Print success message with backup name.  

---

##  How to Run
1. Save the script as `exer4.1.sh`.  
2. Give it execute permission and run:
   ```bash
   chmod +x exer4.1.sh
   ./exer4.1.sh
   ```
## Commands Used:

- `cp -r` → copy directory recursively.
- `tar -czf` → create compressed tar archive.
- `rm -r` → remove backup folder after compression.
- `date +%Y-%m-%d` → fetch current date in YYYY-MM-DD format.

## Sources and AI usage

- AI prompts used to build step-by-step script explanation.
- Concepts learnt with help of ChatGPT (tar usage, error handling).