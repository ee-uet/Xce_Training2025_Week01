 
#!/bin/bash
 
echo -e "Line 1: Hello Guys\n Line 2: I'm Saima :D \nLine 3: Ok bye!\nLine 4: Bht hgya bs,thak gi hun." >file_content.txt  #not appending(>>),it will overwrite ok? , -e tells echo to recognize special characters like \n, \t, etc
# Function to read the file line by line and print with line numbers
read_file() {
    local file=$1
    if [[ -f $file ]]; then # Check if the file exists
        local line_number=1
        while  read -r line; do
            echo "$line_number: $line"
            ((line_number++))
        done < "$file" # means input to be read is coming from file and not default by keyboard
    else
        echo "Error: File $file does not exist."
    fi 
} 
read_file "file_content.txt"

