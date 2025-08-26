# Lab Experiment – Shell Scripting

## Lab 1: Basic Shell Scripting
### Exercise 1.1: Hello World
1. Create a new file named `hello.sh`  
2. Add the shebang line:
```
#!/bin/bash
```
Write a command to print `Hello, World!`
```
echo "Hello, World!"
```
Make the scropt executable
```
chmod +x hello.sh
```
Run the script
```
./hello.sh
```
### Exercise 1.2: Variables and User Input
```
#!/bin/bash
echo "Enter your name: "
read name
echo "Nice to meet you $name"

```
### Exercise 1.3: Command-line Arguments
```
#!/bin/bash
num1=$1
num2=$2
sum=$((num1+num2))
echo "Sum of $num1  and $num2 is $sum"
```
## Lab 2: Control Structures
### Exercise 2.1: If-Else Statement
```
#!/bin/bash
num=$1
if [ $((num%2)) -eq 0 ]
then
        echo "Number is even"
else
        echo "Number is odd"
fi
```
### Exercise 2.2: For Loop
```
#!/bin/bash
num=$1
for ((i=1 ;i<11 ;i++))
do
        multiple=$((i*$num))
        echo "$multiple"
done
```
Exercise 2.3: While Loop
```
#!/bin/bash
num=$((RANDOM % 10))
echo "guess a number"
read guess
while [ $guess -ne $num ]
do
        if [ $guess -lt $num ]
        then
                echo "Too Low,guess another number"
                read guess
        else
                echo "Too high,guess another number"
                read guess
        fi
done
echo "Congrats! you guessed the right number"
```
## Lab 3: Functions and Arrays
### Exercise 3.1: Functions
```
#!/bin/bash
factorial(){
        num=$1
        fact=1
        for (( i=2; i<=$num; i++ ))
        do
                fact=$((fact*i))
        done
        echo "$fact"         
}
factorial 1
factorial 4
factorial 5
```
### Exercise 3.2: Arrays
```
#!/bin/bash
arr=("apple" "banana" "mango" "kiwi")
size=${#arr[@]}
for (( i=0; i<size; i++ ))
do
        echo "${arr[i]}"
done

arr+=("orange")
arr+=("dragonfruit")
size=${#arr[@]}
echo "After adding more fruits in array"
for (( i=0; i<size; i++ ))
do
        echo "${arr[i]}"
done
```
### Exercise 3.3: Associative Arrays
```
#!/bin/bash
declare -A cc
cc[Pakistan]="Islamabad"
cc[China]="Beijing"
cc[India]="New Delhi"
cc[Japan]="Tokyo"
cc[Nepal]="Kathmandu"
cc[Bangladesh]="Dhaka"
cc[SriLanka]="Colombo"
cc[Turkey]="Ankara"
cc[SaudiArabia]="Riyadh"
cc[Afghanistan]="Kabul"
cc[Italy]="Rome"
capital(){
echo "enter country name: "
read country
if [[ -n ${cc[$country]} ]] then
echo "The capital of this country is ${cc[$country]}"
else
        echo "Sorry, I don't know the capital of this country"
fi
}
capital
```
## Lab 4: File Operations and Text Processing
### Exercise 4.1: File Reading
```
#!/bin/bash

file="file.txt"
num=1

while read line
do
    echo "$num: $line" 
   (( num++))
done < "$file"

~                
```
### Exercise 4.2: Text Processing
```#!/bin/bash

logfile="log.txt"

echo "Total entries: $(grep -cve '^\s*$' "$logfile")"
echo "Unique usernames:"
awk '{print $2}' "$logfile" | grep -v '^$' | sort -u
echo "Actions per user:"
awk '{print $2}' "$logfile" | grep -v '^$' | sort | uniq -c
```
### Exercise 4.3: File Backup
```
#!/bin/bash

# Script: backup.sh
# Purpose: Backup a specified directory into a compressed tar file with current date

# Directory to backup (pass as argument)
DIR_TO_BACKUP=$1

# Check if directory argument is provided
if [ -z "$DIR_TO_BACKUP" ]; then
    echo "Error: Please provide a directory to backup."
    echo "Usage: $0 /path/to/directory"
    exit 1
fi

# Check if directory exists
if [ ! -d "$DIR_TO_BACKUP" ]; then
    echo "Error: Directory '$DIR_TO_BACKUP' does not exist."
    exit 1
fi

# Create backup file name with current date
BACKUP_FILE="backup_$(basename $DIR_TO_BACKUP)_$(date +%Y-%m-%d).tar.gz"

# Create compressed tar backup
tar -czf "$BACKUP_FILE" "$DIR_TO_BACKUP"

# Success message
echo "Backup of '$DIR_TO_BACKUP' completed successfully: $BACKUP_FILE"
```

