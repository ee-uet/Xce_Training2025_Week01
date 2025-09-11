#!/bin/bash

source "$(dirname "$0")/math_ops.sh"
source "$(dirname "$0")/file_utils.sh"

echo "Shell-Project"
echo "1. Add two numbers"
echo "2. Create file backup"
echo "Choose option: "
read choice

case $choice in
    1) echo "Result: $(add 5 3)" ;;
    2) create_backup $1 ;;
    *) echo "Invalid option" ;;
esac