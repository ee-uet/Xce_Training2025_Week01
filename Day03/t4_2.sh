#!/bin/bash

LOG_FILE="system_log.txt"

# Check if file exists
if [[ ! -f "$LOG_FILE" ]]; then
    echo "Creating sample log file..."
    cat > "$LOG_FILE" << EOF
    2024-01-15 alice login
    2024-01-15 bob login
    2024-01-15 alice file_upload
    2024-01-16 charlie login
    2024-01-16 alice file_download
    2024-01-16 bob logout
    2024-01-17 david login
    2024-01-17 alice logout
    2024-01-17 charlie file_upload
    2024-01-18 bob login
    2024-01-18 alice login
    2024-01-18 david file_download
    2024-01-19 charlie logout
    2024-01-19 bob file_upload
    2024-01-19 alice system_reboot
EOF
fi

################################################################

echo "=== LOG FILE ANALYSIS ==="
echo "File: $LOG_FILE"
echo ""

# a. Total entries
total=$(wc -l < "$LOG_FILE")
echo "a. Total entries: $total"

# b. Unique users
echo ""
echo "b. Unique users:"
awk '{print $2}' "$LOG_FILE" | sort -u

# c. Actions per user
echo ""
echo "c. Actions per user:"

# Get unique users
users=$(awk '{print $2}' "$LOG_FILE" | sort -u)

for user in $users; do
    echo ""
    echo "User: $user"
    
    # Count total actions for this user
    total_actions=$(grep -c " $user " "$LOG_FILE")
    echo "  Total actions: $total_actions"
    
    # Count each action type
    echo "  Action breakdown:"
    grep " $user " "$LOG_FILE" | awk '{print $3}' | sort | uniq -c | \
    while read count action; do
        echo "    $action: $count"
    done
done