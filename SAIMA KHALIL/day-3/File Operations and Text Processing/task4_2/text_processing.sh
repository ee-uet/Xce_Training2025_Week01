 
#!/bin/bash
echo -e "2022-10-01 user1 login\n2022-10-02 user2 logout\n2022-10-03 user1 update\n2022-10-04 user3 login\n2022-10-05 user2 update" > log.txt   
analyze_log() { 
    local file=$1
    if [[ -f $file ]]; then # Check if the file exists
        local total_entries=$(wc -l < "$file") # Count total entries ,-l line count,wc=word count , `<` means input from file   , -w means word count
        echo "Total number of entries: $total_entries"
 
        echo "Unique usernames:"
        cut -d ' ' -fj2 "$file" | sort -u # Extract unique usernames 
        #-d ' ' : delimiter = space.
        #-f 2 : second column chhodo. Matlab sirf usernames nikal aayenge.

        echo "Actions per user:"
        awk '{print $2}' "$file" | sort | uniq -c # Count actions per user,-c counts occurrences of each unique line.
    else
        echo "Error: File $file does not exist."
    fi 
}   
# Main script execution
analyze_log "log.txt"  