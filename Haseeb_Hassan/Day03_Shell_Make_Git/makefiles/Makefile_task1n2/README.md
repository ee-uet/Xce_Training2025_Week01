# Lab 3 - Makefile Task 1n2

## Problem

Create a Makefile to compile a C program consisting of multiple source files into an executable named `hello`. The project structure includes:

- `main.c` - Contains the main function and program entry point
- `functions.c` - Contains the `greet()` function implementation
- `functions.h` - Header file with function declarations
- `Makefile` - Build automation script

The goal is to demonstrate proper use of Makefile syntax, variables, pattern rules, and build targets including compilation, debugging, and cleanup operations.

## Approach

The Makefile implements several key concepts:

1. **Variable Definition**: Using variables for compiler (`CC`), flags (`CFLAGS`, `DEBUGFLAGS`), source files (`SRC`), object files (`OBJ`), and dependencies (`DEPS`)

2. **Pattern Substitution**: Automatically generating object file names from source files using `$(SRC:.c=.o)`

3. **Pattern Rules**: Using `%.o: %.c` to define how to compile any `.c` file into a `.o` file

4. **Automatic Variables**: 
   - `$@` - Target name
   - `$<` - First dependency
   - `$^` - All dependencies

5. **Multiple Targets**: Including `all`, `hello`, `debug`, and `clean` targets

6. **Conditional Compilation**: Debug target that changes compiler flags and rebuilds

## How to Run

### Prerequisites
- GCC compiler installed
- Make utility available
- All source files (`main.c`, `functions.c`, `functions.h`) in the same directory

### Available Make Targets

1. **Build the executable (default)**
   ```bash
   make
   # or
   make all
   # or
   make hello
   ```

2. **Build with debug information**
   ```bash
   make debug
   ```

3. **Clean build artifacts**
   ```bash
   make clean
   ```

4. **Run the program**
   ```bash
   ./hello
   ```

### Complete Build Process
```bash
# Clean any existing files
make clean

# Build the executable
make

# Run the program
./hello
```

## Examples

### Normal Build
```bash
$ make
gcc -Wall -c main.c
gcc -Wall -c functions.c
gcc -Wall -o hello main.o functions.o
```

### Debug Build
```bash
$ make debug
rm -f hello main.o functions.o
gcc -g -Wall -c main.c
gcc -g -Wall -c functions.c
gcc -g -Wall -o hello main.o functions.o
```

### Program Output
```bash
$ ./hello
hello main is runninghello this is functions.c 
```

### Clean Build
```bash
$ make clean
rm -f hello main.o functions.o
```

### File Structure After Build
```
├── main.c
├── functions.c
├── functions.h
├── Makefile
├── main.o          # Generated object file
├── functions.o     # Generated object file
├── hello           # Final executable
└── oldmakefile.txt # Backup/reference file
```

## Known Limitations

1. **Output Formatting**: The program output lacks proper spacing/newlines between messages from main.c and functions.c

2. **Header Dependencies**: While `functions.h` is listed as a dependency, changes to it will rebuild all object files even if not all files include it

3. **Platform Specific**: Makefile assumes Unix-like system (uses `rm -f` command)

4. **No Install Target**: No installation or deployment target provided

5. **Limited Error Handling**: No explicit error handling for missing source files or compilation failures

6. **Hardcoded Executable Name**: The executable name "hello" is hardcoded rather than being configurable

7. **Debug Information**: Debug build removes optimization flags entirely rather than adding debug info to optimized build

## Technical Details

### Makefile Variables Explained
- `CC = gcc` - Specifies the C compiler
- `CFLAGS = -Wall` - Compiler flags for warnings
- `DEBUGFLAGS = -g -Wall` - Debug-specific compiler flags
- `SRC = main.c functions.c` - List of source files
- `OBJ = $(SRC:.c=.o)` - Automatically generates object file names
- `DEPS = functions.h` - Header file dependencies

### Automatic Variables Used
- `$@` - Refers to the target name (e.g., "hello" or "main.o")
- `$<` - Refers to the first prerequisite
- `$^` - Refers to all prerequisites

### Build Process
1. Make checks if `hello` needs to be built
2. Checks if object files need compilation
3. Compiles `.c` files to `.o` files if source is newer
4. Links object files to create final executable

## Sources & AI Usage

- Standard GNU Make documentation for Makefile syntax and variables
- GCC compiler documentation for compilation flags
- Unix/Linux system programming concepts for build automation
- No AI tools were used in creating this Makefile
