# Makefile – Build Automation for C Program

## Introduction
This Makefile automates the compilation of a simple C project consisting of multiple source files (`main.c` and `function.c`).  
It defines rules for building object files, linking them into the final executable, and cleaning up build artifacts.  

---

## Problem
- Compile multiple C source files efficiently.  
- Avoid recompiling unchanged files.  
- Provide a `clean` rule to remove build artifacts.  

---

## Approach
- `CC = gcc` → specifies the compiler.  
- `CFLAGS = -Wall` → enables all warnings for safer code.  
- `TARGET = program` → defines the name of the final executable.  
- `OBJS = main.o function.o` → object files to build and link.  

### Rules
1. **all**  
   Default target that builds the program.  

2. **$(TARGET)**  
   Links object files (`main.o` and `function.o`) into the final executable.  

3. **main.o**  
   Compiles `main.c` into `main.o`.  

4. **function.o**  
   Compiles `function.c` into `function.o`.  

5. **clean**  
   Removes the executable and object files.  

---

# Makefile – Automatic C Project Build with Dependencies

## Introduction
This Makefile automates the build process for a C project.  
It uses wildcard detection for source files, auto-generates dependencies, and provides rules for building, debugging, and cleaning.  

---

## Problem
- Compile all `.c` files in the directory automatically.  
- Generate `.o` object files and link them into an executable.  
- Support debugging builds (`-g` flag).  
- Manage dependencies automatically with `.d` files.  
- Provide a `clean` rule to remove generated files.  

---

## Approach
- `CC = gcc` → Compiler set to `gcc`.  
- `CFLAGS = -Wall` → Enable all warnings.  
- `SRC = $(wildcard *.c)` → Collects all `.c` source files in the directory.  
- `OBJ = $(SRC:.c=.o)` → Converts each `.c` file into `.o`.  
- `TARGET = program` → Defines the output executable name.  

### Rules
1. **all**  
   Builds the final executable.  

2. **$(TARGET)**  
   Links all object files into the final binary.  

3. **%.o: %.c**  
   Compiles each `.c` file into `.o`.  
   - `-MMD -MF` generates `.d` dependency files to track header changes.  

4. **debug**  
   Adds `-g` to `CFLAGS` for debugging symbols, then rebuilds from scratch.  

5. **clean**  
   Removes object files and the executable.  

---

# Makefile – Manage Bash Scripts

## Introduction
This Makefile is designed to manage Bash scripts (`*.sh`) in the project.  
It provides rules for syntax checking, testing, installation, and uninstallation of scripts into a chosen directory (default: `~/bin`).  

---

## Problem
- Ensure all shell scripts are free of syntax errors.  
- Provide a simple way to test scripts.  
- Automate installation and removal of scripts in a local bin directory.  
- Keep scripts executable and easy to run from anywhere.  

---

## Approach
- `files = $(wildcard *.sh)` → Collects all `.sh` scripts in the directory.  
- `LOCATION ?= $(HOME)/bin` → Sets installation path (default `~/bin`).  
- `.PHONY` → Declares targets that are not actual files.  

### Rules
1. **all**  
   Default rule → runs syntax checks.  

2. **syntax_error**  
   Runs `bash -n` on each script to check for errors.  
   Prints `Syntax OK` if successful.  

3. **test**  
   Example test rule → runs `fruits.sh`.  

4. **clean**  
   Placeholder for cleanup (currently prints "Nothing to clean").  

5. **install**  
   - Creates `$(LOCATION)` if it doesn’t exist.  
   - Copies scripts there.  
   - Marks them as executable (`chmod +x`).  

6. **uninstall**  
   Removes installed scripts from `$(LOCATION)`.  

---

## AI usage
In understanding what make files are and also in syntax.