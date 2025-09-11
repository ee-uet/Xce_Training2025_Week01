# Exercise 5.1: Basic Makefile

## Problem
Create a simple C program with main.c and functions.c, write a Makefile to compile these into an executable. Include targets for 'all', 'clean', and individual object files.

## Approach
1. Define compiler and compilation flags as variables
2. Create main target that depends on object files
3. Create object file targets with proper dependencies
4. Add 'all' target that builds and runs the program
5. Include 'clean' target for removing generated files

## Required Files
You need to create these C files in the same directory:

### main.c
```c
#include <stdio.h>
extern void hello_function();

int main() {
    printf("Hello from main!\n");
    hello_function();
    return 0;
}
```

### functions.c
```c
#include <stdio.h>

void hello_function() {
    printf("Hello from functions.c!\n");
}
```

## How to Run

### Setup
```bash
# Create the required C files first
# Copy the Makefile to the same directory
```

### Compilation and Execution
```bash
make          # Compiles and runs the program
make all      # Same as above
make main     # Just compile, don't run
make clean    # Remove generated files
```

## Example Output
```bash
$ make
gcc -Wall -c main.c
gcc -o main main.o
./main
Hello from main!
Hello from functions.c!

$ make clean
rm -f main.o main
```

## Makefile Structure
```makefile
CC = gcc
CFLAGS = -Wall

all: main
	./main

main: main.o
	$(CC) -o main main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f main.o main
```

## Key Concepts Demonstrated
- **Variables**: CC and CFLAGS for maintainable configuration
- **Target Dependencies**: main depends on main.o
- **Automatic Variables**: $@ (target), $^ (all dependencies)
- **Tab Indentation**: Critical requirement for makefile commands
- **Clean Target**: Standard practice for removing generated files


## Design Notes
- Uses standard compiler flags (-Wall for warnings)
- Separates compilation and linking steps
- Follows conventional target naming
- Includes executable in 'all' target for demonstration

## Assumptions & Edge Cases
- Assumes GCC compiler is available
- Assumes source files exist in same directory
- No dependency on header files (simple example)
- Standard Unix-like environment

## Known Limitations
- Hardcoded source file names (not scalable)
- No automatic dependency generation
- No debug/release build options
- Single source file compilation only

## Makefile Best Practices Shown
1. Use variables for compiler and flags
2. Proper target:dependency syntax
3. Tab indentation for commands
4. Standard target names (all, clean)
5. Remove generated files in clean target

## Sources & AI Usage
- Original template from lab manual
- Looked up Makefile syntax on GNU Make documentation
- Google search for common Makefile patterns