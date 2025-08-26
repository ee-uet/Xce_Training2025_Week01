#!/bin/bash
source scripts/file_utils.sh

test_create_backup() {
    echo "test content" > test_file.txt
    create_backup "test_file.txt"
    
    if [ -f "test_file.txt.bak" ]; then
        echo "create_backup test passed"
        rm test_file.txt test_file.txt.bak
    else
        echo "create_backup test failed"
        exit 1
    fi
}

test_create_backup
echo "File utils test passed!"