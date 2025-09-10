# User Greeting Bash Script

## Problem
The goal is to write a Bash script that:
1. Prompts the user to enter their name.
2. Reads the input.
3. Greets the user with a personalized welcome message.

## Approach
- Use the `echo` command to display prompts and messages.  
- Use the `read` command to capture user input and store it in a variable (`username`).  
- Use variable expansion (`$username`) to print the personalized greeting.  

## How to Run
1. Save the script as `greet.sh`.  
2. Make it executable:  
   ```bash
   chmod +x E1_2.sh
    ./E1_2.sh

## Examples
$ ./greet.sh
Enter User name
Hafiz
Hello, Hafiz! welcome to shell scripting

$ ./greet.sh
Enter User name
Alice
Hello, Alice! welcome to shell scripting

## Known Limitations

Script only accepts a single word for the username (e.g., "John Doe" would only capture "John").

No input validation is implemented (empty input will still output a greeting).

Requires Bash shell (/bin/bash) to be installed on the system.