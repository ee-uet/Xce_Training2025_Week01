## Project Structure

```
Lab4_FileOprtionTextProcessing/
├── README.md
├── files_imp/
├── files_imp_2025-08-25.tar.gz     # Generated tar file
├── file_backup.sh       # Directory backup utility
├── file_read.sh         # Line-by-line file reader
├── text_processing.sh   # Log file analyzer
├── input.txt           # Sample input file
└── log.txt             # Sample log file (to be created)
```

## Scripts Overview

| Script               | Description                  | Input Required |
|----------------------|------------------------------|----------------|
| `file_read.sh`       | Reads and numbers file lines | `input.txt`    |
| `text_processing.sh` | Analyzes log entries         | `log.txt`      |
| `file_backup.sh`     | Creates directory backups    | User input     |

## Exercise Details

### Exercise 4.1: File Reading (`file_read.sh`)
- Reads `input.txt` line by line
- Displays each line with its line number
- Demonstrates basic file I/O operations

### Exercise 4.2: Text Processing (`text_processing.sh`)
- Processes log files with format: "YYYY-MM-DD username action"
- Counts total log entries
- Lists unique usernames
- Counts actions per user

### Exercise 4.3: File Backup (`file_backup.sh`)
- Creates compressed tar backups of directories
- Uses current date in backup filename
- Includes error handling for non-existent directories

## How to Run

### Setup
```bash
# Make scripts executable
chmod +x *.sh

# Create sample log file for text processing
cat > log.txt << EOF
2024-01-15 alice login
2024-01-15 bob logout
2024-01-16 alice download
2024-01-16 charlie login
2024-01-17 alice logout
EOF
```

### Running Scripts

**File Reading:**
```bash
./file_read.sh
```

**Text Processing:**
```bash
./text_processing.sh
```

**File Backup:**
```bash
./file_backup.sh
# Enter directory path when prompted
```

## Expected Output

**File Reading Output:**
```
1: Naqi ul hassan
2: Roll no 2022-EE-164
```

**Text Processing Output:**
```
Total number of entries are 5
Unique user
alice
bob
charlie
User actions
3 alice
1 bob
1 charlie
```

**File Backup Output:**
```
Enter the directory path: /home/user/documents
Backup successful: documents_2024-09-07.tar.gz
```

## Key Features

- **Error Handling**: All scripts include proper error checking
- **Date Integration**: Backups include current date in filename format
- **Text Analysis**: Automated sorting and counting of log data
- **Interactive Input**: User-friendly prompts for directory selection
- **Cross-platform**: Works on Linux, macOS, and WSL

## Requirements

- Bash shell (version 4.0+)
- Standard Unix utilities: `tar`, `awk`, `sort`, `uniq`, `wc`
- Write permissions in working directory
- Input files as specified in each exercise

## Notes

- The `input.txt` file is provided with sample content
- Create `log.txt` with the specified format for text processing
- Backup files are created in the current directory
- All scripts use relative paths for portability
