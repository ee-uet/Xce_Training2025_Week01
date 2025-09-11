# Shell Script Project with Makefile

The goal of this project is to demonstrate how to organize multiple shell scripts and manage them using a Makefile for syntax checking, testing, and installation.

## Approach 

1. **Shell Scripts**  
    - `script1.sh` : Prints "Hello from script1".  
    - `script2.sh` : Prints "Hello from script2".  

2. **Test Scripts**  
    - `test_script1.sh` : Runs `script1.sh` to verify it works correctly.  
    - `test_script2.sh` : Runs `script2.sh` to verify it works correctly.  

3. **Makefile**  
    - The Makefile is used to automate syntax checking, testing, and installation.  
    - Targets:
        - `all` / `check` : Checks the syntax of all shell scripts using `bash -n`.  
        - `test` : Runs the test scripts to verify the functionality of each shell script.  
        - `install` : Copies the shell scripts to the specified directory `/home/aleeza/copied_5.3`.  
        - `clean` : Prints a message (nothing to clean for shell scripts).  

## How to Run

1. Open a terminal in the project directory.  
2. Run `make` or `make check` to perform a syntax check on all scripts.  
3. Run `make test` to execute the test scripts and verify outputs.  
4. Run `make install` to copy the scripts to `/home/aleeza/copied_5.3`.  
5. Run `make clean` to see the cleanup message. 

## Known Limitations

None

## Sources & AI Usage

- How to install scripts from one directory to another
- Makefile structure
- Overall refining