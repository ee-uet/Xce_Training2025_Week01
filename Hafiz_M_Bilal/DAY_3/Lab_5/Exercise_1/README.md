# C Project: E5_1

## Problem
Create a C program split into multiple source files (`E5_1_main.c`, `E5_1_function.c`) and compile it using a Makefile. The program should build and run correctly.

## Approach
1. Split your C program into separate source files for better modularity:
   - `E5_1_main.c` – contains the `main` function.
   - `E5_1_function.c` – contains helper functions used by `main`.
2. Create a `Makefile` to automate compilation:
   - Set the compiler (`gcc`) and flags (`-Wall -g` for warnings and debugging).
   - Define the target executable name as `E5_1`.
   - Specify all source files in the `SRC` variable.
   - Include `all`, `run`, and `clean` rules.
3. The `run` rule depends on the target and executes the program.
4. The `clean` rule removes the compiled executable to allow a fresh build.

## How to Run
1. Open a terminal in the project directory.
2. Build and run the program using:
   ```bash
   make
make run
make clean

## Example Output

Assuming E5_1 prints Hello World!, running:

make run


Output:

Hello World!

## Known Limitations

Assumes all source files compile without errors.

Makefile uses ./E5_1 directly; may require adjustment on non-Unix systems.

Does not handle external library dependencies.