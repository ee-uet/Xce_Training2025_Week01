

## Problem
- **t1_1:** Print "Hello, World!"  
- **t1_2:** Ask for the user's name, greet them, then read a number and echo it  
- **t1_3:** Accept two numbers as arguments and print their sum  

## Approach
- Use `#!/bin/bash` so scripts run with Bash  
- `read -p` used for interactive input  
- `$1`, `$2` used for command-line args  
- `$(( ))` used for integer arithmetic  

## How to Run
1. **Make scripts executable:**
   ```bash
   chmod +x t1_1 t1_2 t1_3
2. **Run each task:**

Hello World:
    ./t1_1
Greeting (interactive):
    ./t1_2
Sum with arguments:
    ./t1_3 4 7

## Test Cases
t1_1
$ ./t1_1
    Hello, World!

t1_2
$ ./t1_2
    Enter Name: Ali
    Hello Ali
    Enter Number: 42
    You entered: 42

t1_3
$ ./t1_3 5 8
    Sum is 13
    
## Known Limitations
1. t1_3 does not check if arguments are missing or non-numeric
2. t1_2 requires manual input
   

