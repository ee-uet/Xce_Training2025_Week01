#1. Create a log file with entries of the format: "YYYY-MM-DD username action"
#2. Write a script that:
#  a. Counts the total number of entries
#  b. Lists unique usernames
#  c. Counts actions per user

#!/bin/bash
# Create a log file with entries of the format: "YYYY-MM-DD username action"
echo -e "2022-10-01 user1 login\n2022-10-02 user2 logout\n2022-10-03 user1 update\n2022-10-04 user3 login\n2022-10-05 user2 update" > log.txt   
# Function to analyze the log file
analyze_log() { 
    local file=$1
    if [[ -f $file ]]; then # Check if the file exists
        local total_entries=$(wc -l < "$file") # Count total entries ,-l line count,wc=word count , `<` means input from file   , -w means word count
        echo "Total number of entries: $total_entries"

        echo "Unique usernames:"
        cut -d ' ' -f 2 "$file" | sort -u # Extract unique usernames 
        #-d ' ' → delimiter = space.
        #-f 2 → second column chhodo. Matlab sirf usernames nikal aayenge.

        echo "Actions per user:"
        awk '{print $2}' "$file" | sort | uniq -c # Count actions per user,-c counts occurrences of each unique line.
    else
        echo "Error: File $file does not exist."
    fi 
}   
# Main script execution
analyze_log "log.txt" 