# Makefile (Exercises 5.1–5.3)

## Problem
- **Exercise 5.1 (Basic Makefile):**
  - Create a simple C program with `main.c` and `functions.c`.
  - Write a Makefile to compile these into an executable.
  - Include targets for `all`, `clean`, and individual object files.

- **Exercise 5.2 (Advanced Makefile):**
  - Extend the Makefile to handle multiple source files automatically.
  - Add a `debug` target that compiles with debugging symbols.
  - Implement dependency tracking for header files.

- **Exercise 5.3 (Makefile for a Shell Script Project):**
  - Create a project with multiple shell scripts.
  - Write a Makefile that:
    - checks scripts for syntax errors,
    - runs unit tests (if available),
    - installs scripts to a specified directory.

## Approach
- **5.1:** A minimal Makefile compiles `sample.c` → `sample.o` and links to `sample` with `all` and `clean` targets.
- **5.2:** Use `wildcard` to auto-discover `.c` files, pattern rules to build `.o` files and `-MMD` to generate dependency `.d` files; add `debug` flag set for debugging builds.
- **5.3:** Use `bash -n` for syntax checks, execute test scripts as unit tests, and use `install` to copy scripts to an install directory with correct permissions.

## How to Run
    make all
    
## Test Cases
1. Exercise 5.1: Add sample.c that prints something. Running make all should compile and run the executable.
2. Exercise 5.2: Add multiple .c files. make all should build out executable. make debug should compile with -g.
3. Exercise 5.3: Add a scripts/hello.sh and tests/test_hello.sh that runs scripts/hello.sh and checks output. make all should run the checks and tests, and make install INSTALL_DIR=install/ should copy scripts there.

## Sources & AI Usage
1. I used short helper examples (wildcard, -MMD, bash -n) that are common in Makefile templates.
