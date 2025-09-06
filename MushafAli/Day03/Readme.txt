Lab#03 – Bash Scripting & Makefile Automation

This lab demonstrates Bash scripting and Makefile tasks including printing messages, reading input, arithmetic operations, conditionals, loops, arrays, associative arrays, file handling, logging, backup, and compiling C programs.

Task #1 – Basic Bash Commands

Print Message
echo "Hello , Word!"


###Prints a simple greeting message.

Greet User
Prompts for a username and greets the user:
Assala o alikum <username> how are you?


###Sum of Two Numbers

Takes two numbers as command-line arguments ($1 and $2) and prints their sum:

Sum of 2 numbers is : <num1+num2>


Task #2 – Conditionals & Loops

###Even or Odd

Prompts the user to enter a number and checks if it is even or odd.


###Multiplication Table

Uses the first command-line argument as input and prints its first 10 multiples.

###Random Number Guessing Game

Generates a random number between 1–10.

User keeps guessing until correct.

Provides hints if the guess is higher or lower.


Task #3 – Functions, Arrays & Associative Arrays


###Factorial Function

Calculates factorial of a number (passed as first argument) using a loop.

###Arrays

Stores fruits in an array.

Adds "Mango" and prints all elements.

###Associative Arrays

Stores countries and capitals in an associative array.

User enters a country name and the script prints its capital or a “not exist” message.


Task #4 – File Handling & Logging

Reading File

Reads each line of text.txt and prints with line number:

processing :<line_number> <line_content>


Logging User Actions

Prompts user for username and action.

Appends a timestamped entry to script.log.

Prints total lines and action counts per user.

Backup Script

Compresses the LAB#01 directory into a .tar.gz backup file with the current date.

Stores it in the specified backup directory.


Task #5 – Makefiles

###Simple Makefile

Compiles main.c and functions.c into program.

clean target removes object files and the executable.

####Advanced Makefile

Uses variables, pattern rules, and dependency files.

Supports debug compilation and cleaning.

###Shell Script Management Makefile

check – syntax check of all scripts.

test – runs all test scripts.

install – copies scripts to backup directory and makes them executable.

###Execution Instructions
Run Bash Script
bash lab01.sh <num1> <num2>


<num1> and <num2> are used in sum and multiplication tasks.

Run Makefile
make           # compile program
make debug     # compile with debug symbols
make clean     # remove object files and executable

Run Script Management
make check
make test
make install



###Expected Output Summary

1)Hello message & user greeting

2)Sum of two numbers

3)Even/odd check

4)Multiplication table

5)Random number guessing game

5)Factorial calculation

6)Array and associative array outputs

7)File reading (text.txt) and logging (script.log)

8)Backup creation (backup_YYYY-MM-DD.tar.gz)

9)C program compilation and Makefile operations








########### AI USAGE ###############
use chatgpt for some commands revision and use 