# C Project: E5_2

## Problem
Create a C program compiled using a Makefile with automatic dependency generation, debug mode, and separate build rules for objects. The program should be modular and maintainable, supporting debug builds and proper cleanup.

## Approach
1. **Source Files**: All `.c` files in the directory are included automatically using `wildcard`.
2. **Object Files**: Each `.c` file is compiled into a `.o` file.
3. **Dependency Files**: `.d` files are generated for each source file to track dependencies (`-MMD` flag).
4. **Makefile Rules**:
   - `all`: Default rule to build the executable `E5_2`.
   - `$(executable)`: Links all object files into the final executable.
   - `%.o: %.c`: Compiles each `.c` file into a `.o` file, generating dependency files.
   - `-include $(depend_files)`: Includes dependency files automatically to rebuild only necessary files.
   - `debug`: Sets `CFLAGS` to include debug flags (`-g`) and rebuilds executable.
   - `run`: Runs the executable.
   - `clean`: Deletes the executable, object files, and dependency files.

## How to Run
1. Open a terminal in the project directory.
2. Build the program:
   ```bash
   make
Run the program:

make run


Build in debug mode:

make debug


Clean all build files:

make clean

## Example Output

Assuming the executable prints Program Running, running:

make run


Output:

Program Running

## Known Limitations

Assumes all .c files are error-free and compile successfully.

The Makefile is Unix-specific; may require adjustments for Windows.

Does not handle external libraries or non-standard include paths.

## Sources & AI Usage

This Makefile was AI-assisted (ChatGPT). I used AI to understand:

How to automatically build C projects with multiple source files.

How to use pattern rules (%.o: %.c) for object file compilation.

How to generate header dependencies with -MMD and include them with -include.

How to define custom targets like debug, run, and clean.

All code was implemented manually after guidance, and all logic is original.

## What I Verified

I verified the Makefile’s correctness by testing:

Normal build (make) → executable is created successfully.

Debug build (make debug) → executable contains debug symbols (-g).

Run target (make run) → program executes correctly.

Clean target (make clean) → removes all object, dependency, and executable files.

Header changes → modifying .h files triggers correct recompilation of dependent .c files.