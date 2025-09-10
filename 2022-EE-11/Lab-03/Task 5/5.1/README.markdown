# Makefile: C Program Build Automation

## Problem
This Makefile automates the compilation and linking of a C program (`myprogram`) from multiple source files (`main.c`, `functions.c`) with a header file (`functions.h`).

## Approach
The Makefile:
- Defines the compiler (`gcc`) and flags (`-Wall -Wextra -std=c99`).
- Specifies source files (`main.c`, `functions.c`), object files (`main.o`, `functions.o`), and the target executable (`myprogram`).
- Provides rules to compile source files into object files and link them into the executable.
- Includes a `clean` rule to remove generated files.

## Walkthrough
1. **Variables**:
   - `CC = gcc`: Sets the compiler to `gcc`.
   - `CFLAGS = -Wall -Wextra -std=c99`: Enables warnings and C99 standard.
   - `TARGET = myprogram`: Names the final executable.
   - `SOURCES = main.c functions.c`: Lists source files.
   - `OBJECTS = main.o functions.o`: Lists object files.
2. **Rules**:
   - `all: $(TARGET)`: Default target to build the executable.
   - `$(TARGET): $(OBJECTS)`: Links object files into the executable using `gcc`.
   - `main.o: main.c functions.h`: Compiles `main.c` into `main.o`, depending on `functions.h`.
   - `functions.o: functions.c functions.h`: Compiles `functions.c` into `functions.o`, depending on `functions.h`.
   - `clean`: Removes object files and the executable.
3. **Phony Targets**:
   - `.PHONY: all clean`: Ensures `all` and `clean` are treated as non-file targets.

## How to Run
1. **Prerequisites**: Requires `gcc` and `make` in a Unix-like environment (e.g., Linux, macOS, WSL).
2. **Prepare Files**: Ensure `main.c`, `functions.c`, and `functions.h` exist in the same directory as the Makefile.
3. **Build**: Run:
   ```bash
   make
   ```
   This compiles `main.c` and `functions.c` into object files and links them into `myprogram`.
4. **Execute**: Run the program:
   ```bash
   ./myprogram
   ```
5. **Clean**: Remove generated files:
   ```bash
   make clean
   ```

## Examples
### Sample Run
Assuming `main.c` and `functions.c` contain a simple program:
```bash
$ make
gcc -Wall -Wextra -std=c99 -c main.c
gcc -Wall -Wextra -std=c99 -c functions.c
gcc main.o functions.o -o myprogram
$ ./myprogram
[Program output depends on main.c and functions.c]
$ make clean
rm -f main.o functions.o myprogram
```

## Syntactical Shorthands Explained
- `CC`: Variable for the compiler (`gcc`).
- `CFLAGS`: Compiler flags (`-Wall`: all warnings, `-Wextra`: extra warnings, `-std=c99`: C99 standard).
- `TARGET`: Variable for the executable name.
- `SOURCES`/`OBJECTS`: Lists of source and object files.
- `$(VAR)`: Variable substitution (e.g., `$(CC)` expands to `gcc`).
- `-c`: Compiles source files to object files without linking.
- `-o`: Specifies the output file name.
- `.PHONY`: Declares targets that don’t produce files.
- `rm -f`: Removes files without prompting (`-f`: force).
- `all`/`clean`: Common Makefile target names for building and cleaning.