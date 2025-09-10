```bash
#!/bin/bash

# Create a temporary test file
test_file="test.txt"
echo "Test content" > "$test_file"

# Run backup.sh
../scripts/backup.sh "$test_file"

# Check if backup file was created
backup_file=$(ls test_backup_*.txt 2>/dev/null)     #dev/null suppresses error if no files found
if [[ -f "$backup_file" ]]; then
    echo "Test passed: backup.sh created '$backup_file'"
    rm "$test_file" "$backup_file"
    exit 0
else
    echo "Test failed: backup.sh did not create a backup file" >&2
    rm "$test_file"
    exit 1
fi
```