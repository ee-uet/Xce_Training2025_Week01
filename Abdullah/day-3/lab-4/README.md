# Lab 4: File Operations and Text Processing

## Problem
1. **File Reading (Exercise 4.1)**: Create a text file with content, write script to read file line by line and print each line with line numbers
2. **Text Processing (Exercise 4.2)**: Create log file with date-username-action format, write script to count entries, list unique usernames, and count actions per user
3. **File Backup (Exercise 4.3)**: Write script to create compressed backup of specified directory with current date in filename and error handling

## Approach

### File Reading
1. Create sample text file with multiple lines
2. Use while loop with IFS= and read -r for proper line reading
3. Maintain line counter and print formatted output
4. Include file existence checking

### Text Processing
1. Generate sample log file with structured data
2. Use wc command to count total entries
3. Use awk to extract usernames and find unique ones
4. Implement action counting per user with associative arrays in awk

### File Backup
1. Get directory name from user input
2. Check if directory exists before proceeding
3. Generate backup filename with current date
4. Use tar with compression for backup creation
5. Implement proper error handling and success reporting

## How to Run

### Make Scripts Executable
```bash
chmod +x *.sh
```

### File Reading
```bash
./file_reading.sh
```

### Text Processing
```bash
./text_processing.sh
```

### File Backup
```bash
./backup_script.sh
```

## Example Output

### File Reading
```
File Processing Started!
Line 1: Hello, My Name is Muhammad Abdullah.
Line 2: I'm a student in my Senior Year.
Line 3: I'm happy that I'm about to be graduated in next 10 months.
Line 4: Thanks!!!
```

### Text Processing
```
Total Entries: 6
Unique Usernames:
abdul101
abdul102
abdul104
Action Count per User:
abdul101 2
abdul102 3
abdul104 1
```

### File Backup
```
Enter the Directory name: myproject
Backup successfully created: backup_2024-01-15.tar.gz
```

## Design Notes
- File reading uses proper IFS handling to preserve whitespace
- Text processing leverages awk for efficient data extraction
- Backup script uses tar with gzip compression for efficiency
- All scripts include appropriate error checking

## Key Concepts Demonstrated
- **File Reading**: `while IFS= read -r line` for safe line reading
- **Line Counting**: Incrementing counters in loops
- **File Existence**: `[ -f "$filename" ]` for file checking
- **Text Processing**: awk for field extraction and data analysis
- **Here Documents**: `cat > file << EOF` for file creation
- **Date Formatting**: `date +%Y-%m-%d` for consistent date strings
- **Directory Checking**: `[ -d "$directory" ]` for directory validation
- **Tar Archives**: `tar -czf` for compressed archive creation

## File Operations Used
- **wc -l**: Count lines in file
- **awk**: Text processing and field extraction
- **sort | uniq**: Find unique values
- **tar -czf**: Create compressed archive
- **date**: Generate formatted timestamps

## Assumptions & Edge Cases
- File reading assumes text files with standard line endings
- Text processing expects space-separated log format
- Backup script handles non-existent directories gracefully
- All scripts include basic error reporting

## Known Limitations
- File reading doesn't handle very large files efficiently
- Text processing assumes consistent log format
- Backup script doesn't handle symbolic links specially
- No progress indication for large backup operations

## Error Handling Implemented
- **File existence checks**: Before attempting to read files
- **Directory validation**: Before creating backups
- **Tar operation validation**: Check if backup creation succeeded
- **User feedback**: Clear error messages and success confirmations

## Algorithm Details

### Safe File Reading
```bash
while IFS= read -r line; do
    echo "Line $line_number: $line"
    ((line_number++))
done < "$file_name"
```

### AWK Text Processing
```bash
# Count actions per user
awk '{count[$2]++} END {for (user in count) print user, count[user]}' "$file_name"

# Extract unique usernames
awk '{print $2}' "$file_name" | sort | uniq
```

### Date-based Backup Names
```bash
current_date=$(date +%Y-%m-%d)
backup_name="backup_${current_date}.tar.gz"
```


## Sources & AI Usage
- Original template code from lab manual
- Standard Unix text processing techniques
- Looked up Google for specific command usage