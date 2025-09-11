# Exercise 5.2: Advanced Makefile

## Overview
This exercise extends a basic Makefile to provide **better automation and flexibility** when working with C projects.  
The Makefile includes:
1. Automatic handling of **multiple source files** (`*.c`).
2. A `debug` target that enables **debugging symbols** (`-g`).
3. Automatic **dependency tracking** for header files (`.h`).

---

## Code Structure

### Makefile Features
1. **Source and Object Management**
   - Uses `wildcard` to collect all `.c` files in the directory.
   - Converts them into corresponding `.o` object files automatically.

2. **Targets**
   - `all`: Default target, builds the executable.
   - `debug`: Builds the program with debugging flags (`-g`).
   - `clean`: Removes build artifacts (`.o`, `.d`, executable).

3. **Dependency Tracking**
   - Uses `-MMD` during compilation to generate `.d` files.
   - Ensures correct recompilation when header files are modified.

---

## How It Works

1. **Default Build (`make`)**

   * Compiles all `.c` files into `.o` files.
   * Links them into the final executable `myprogram`.

2. **Debug Build (`make debug`)**

   * Cleans previous builds.
   * Compiles with `-g` to include debugging symbols.

3. **Dependency Tracking**

   * For each `.c` file, a `.d` file is generated.
   * If a header file changes, only the affected `.c` files are rebuilt.

---
## Compilation & Execution

### Build

```bash
make -f makefile.mak
```

### Run

```bash
./myprogram
```

Expected output:

```
Sum = 42
```

## Verification

### Directory Setup

I created a dedicated directory for the exercise.
Placed all source files inside it, e.g.:
```sh
add.c
cfile.c
```
The Makefile automatically detected all .c files inside the directory and compiled them.
Manual Check

Input: x = 15, y = 27

Expected output: 15 + 27 = 42
Program printed:

Sum = 42


## Multiple Source File Handling

Added an extra file subtract.c with a subtract() function.
Re-ran make.
The Makefile automatically recompiled all sources and linked them.

## Reference
- Slides
- AI