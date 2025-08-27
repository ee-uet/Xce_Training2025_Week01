#!/bin/bash

# Create a sample text file
sample_file="sample_text.txt"
cat > "$sample_file" << EOF
This is line one of our sample file.
Here we have the second line with some content.
The third line contains different information.
Line four has more text for processing.
Finally, this is the fifth and last line.
EOF

echo "Created sample file: $sample_file"
echo "Reading file line by line with line numbers:"

# Function to read file line by line with line numbers
read_file_with_numbers() {
    local filename="$1"
    local line_num=1
    
    if [[ ! -f "$filename" ]]; then
        echo "Error: File '$filename' not found!"
        return 1
    fi
    
    while IFS= read -r line; do
        printf "%3d: %s\n" "$line_num" "$line"
        ((line_num++))
    done < "$filename"
}

read_file_with_numbers "$sample_file"
echo






# Create a sample log file
log_file="sample_log.txt"
cat > "$log_file" << EOF
2024-01-15 alice login
2024-01-15 bob upload
2024-01-15 alice download
2024-01-16 charlie login
2024-01-16 alice logout
2024-01-16 bob delete
2024-01-17 david login
2024-01-17 alice login
2024-01-17 charlie upload
2024-01-18 bob login
2024-01-18 david download
2024-01-18 alice logout
EOF

echo "Created log file: $log_file"
echo "Log Analysis Results:"

# Function to analyze log file
analyze_log() {
    local logfile="$1"
    
    if [[ ! -f "$logfile" ]]; then
        echo "Error: Log file '$logfile' not found!"
        return 1
    fi
    
    # Count total entries
    total_entries=$(wc -l < "$logfile")
    echo "Total log entries: $total_entries"
    echo
    
    # List unique usernames
    echo "Unique usernames:"
    awk '{print $2}' "$logfile" | sort -u | nl
    echo
    
    # Count actions per user
    echo "Actions per user:"
    awk '{print $2}' "$logfile" | sort | uniq -c | while read count user; do
        printf "%-10s: %d actions\n" "$user" "$count"
    done
    echo
    
    # Bonus: Show action types
    echo "Action breakdown:"
    awk '{print $3}' "$logfile" | sort | uniq -c | while read count action; do
        printf "%-10s: %d times\n" "$action" "$count"
    done
}

analyze_log "$log_file"
echo








# Function to create directory backup
backup_directory() {
    local source_dir="$1"
    local backup_base_name="${2:-backup}"
    
    # Check if source directory exists
    if [[ ! -d "$source_dir" ]]; then
        echo "Error: Directory '$source_dir' does not exist!"
        return 1
    fi
    
    # Create backup filename with current date
    local current_date=$(date +"%Y%m%d_%H%M%S")
    local backup_filename="${backup_base_name}_${current_date}.tar.gz"
    
    echo "Creating backup of '$source_dir'..."
    echo "Backup file: $backup_filename"
    
    # Create the backup
    if tar -czf "$backup_filename" -C "$(dirname "$source_dir")" "$(basename "$source_dir")" 2>/dev/null; then
        local backup_size=$(du -h "$backup_filename" | cut -f1)
        echo "Success! Backup created: $backup_filename (Size: $backup_size)"
        echo "Backup contains:"
        tar -tzf "$backup_filename" | head -10
        if [[ $(tar -tzf "$backup_filename" | wc -l) -gt 10 ]]; then
            echo "... and $(($(tar -tzf "$backup_filename" | wc -l) - 10)) more files"
        fi
    else
        echo "Error: Failed to create backup!"
        return 1
    fi
}

# Create a test directory with some files for backup demonstration
test_dir="test_backup_dir"
mkdir -p "$test_dir"
echo "Sample file 1" > "$test_dir/file1.txt"
echo "Sample file 2" > "$test_dir/file2.txt"
mkdir -p "$test_dir/subdir"
echo "Nested file" > "$test_dir/subdir/nested.txt"

echo "Created test directory: $test_dir"
echo "Testing backup function:"

# Test successful backup
backup_directory "$test_dir" "test_backup"
echo

# Test error handling
echo "Testing error handling with non-existent directory:"
backup_directory "non_existent_dir" "error_test"
echo

# Cleanup function
cleanup_files() {
    echo "Cleaning up created files..."
    rm -f "$sample_file" "$log_file" *.tar.gz
    rm -rf "$test_dir"
    echo "Cleanup completed."
}
