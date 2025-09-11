# Problem
- Create a project with multiple shell scripts
- Write a Makefile that:
   a. Checks scripts for syntax errors
   b. Runs unit tests (if available)
   c. Installs scripts to a specified directory

#
**Approach**  
**syntax testing**

- bash -n file.sh → checks if the script has any syntax errors (but does not run it).

- The loop runs over every file in $(SCRIPTS) (all files matching script*.sh).

- If even one script has an error, it stops (exit 1).

- If all scripts are fine, it prints: "All scripts passed syntax check!".    
  
**Unit testing**  
- Runs every file in $(TESTS) (all files starting with test_*.sh).

- Each test script checks the expected output of your main scripts.

- If any test fails, the loop exits immediately (exit 1).

- If all tests succeed, it prints: "All tests passed!".  
- 
**Installing scripts**    
- This target depends on syntax and test. That means scripts are only installed if they pass syntax check and tests first.

- install -m 755:  
   Copies the script into the target folder (INSTALL_DIR).

- Sets permissions 755 → (owner can read/write/execute, others can read/execute).

- Prints confirmation when done.
#
**How to run**
1. Open Terminal in the folder where all files and Makefile are saved.
2. Build the Program by typing make on the terminal. 
3. Clean the Build Files  
  'make clean'  
#
**Example**  
Output after running make command on the   terminal:    
Checking syntax  
All scripts passed syntax check!   
Running unit tests  
All tests passed!  
Installing scripts to /mnt/c/Users/123/Desktop/xcelerium...  
install -m 755 script1.sh script2.sh     /mnt/c/Users/123/Desktop/xcelerium  
Scripts installed successfully!   
#
**Verification / What I Learned**  
-  I understood the syntax and working of the script using the lab slides.
- For the installing part, I was unable to figure out the correct command, so I took help from AI to get the proper install -m 755 usage and then understood how it works (copying files into the directory with correct permissions).