#!/bin/bash

# Function to compute string length
string_length() {
    local str="$1"  # Input string
    echo "${#str}"  # Output the length of the string
}

# Example usage
if [[ $# -eq 1 ]]; then
    string_length "$1"
else
    # Error handling for incorrect usage
    echo "Usage: $0 <string>" >&2   # Print usage to stderr
    exit 1
fi
