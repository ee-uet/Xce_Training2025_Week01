
---

# Shell Scripting & Makefile Exercises – Part 5

This repository contains solutions for two exercises focusing on **Makefiles** to automate C program compilation.

---

## Exercise 5.1: Basic Makefile

### Problem

* Create a simple C program with `main.c` and `functions.c`.
* Write a Makefile to compile these into an executable.
* Include targets for:

  * `all` → builds the program
  * `clean` → removes compiled files
  * individual object files (`main.o`, `functions.o`)

### Approach

* Defined rules for building `program` from `main.o` and `functions.o`.
* Each `.o` file depends on its respective `.c` file.
* Used `gcc` for compilation.
* Added `clean` rule to remove all generated files.

### Example

```bash
$ make
gcc -c -o main.o main.c
gcc -c -o functions.o functions.c
gcc -o program main.o functions.o

$ ./program
Hello from program!

$ make clean
rm -f main.o functions.o program
```

### Known Limitations

* Must manually update Makefile if new `.c` files are added.
* No debug build option.

---

## Exercise 5.2: Advanced Makefile

### Problem

* Extend Makefile to handle multiple `.c` files automatically.
* Add a `debug` target that includes debugging symbols (`-g`).
* Implement **header dependency tracking** so that changes in `.h` files trigger recompilation.

### Approach

* Used `wildcard` to automatically detect all `.c` files.
* Converted them into `.o` objects and `.d` dependency files.
* Added `debug` target by appending `-g` to `CFLAGS`.
* Used `gcc -MM` to generate dependency files.
* Included dependencies with `-include $(DEPS)` to handle header changes.

### Example

```bash
$ make
gcc -Wall -std=c99 -c -o main.o main.c
gcc -Wall -std=c99 -c -o functions.o functions.c
gcc -o program main.o functions.o

$ make debug
gcc -Wall -std=c99 -g -c -o main.o main.c
gcc -Wall -std=c99 -g -c -o functions.o functions.c
gcc -o program main.o functions.o

$ ./program
Hello from program!

$ make clean
rm -f main.o functions.o main.d functions.d program
```

### Known Limitations

* Works only in the current directory (no recursive subdirectory build).

---

## How to Run

1. Ensure you have `gcc` and `make` installed.

2. Place `main.c`, `functions.c`, and the Makefile in the same folder.

3. Build the program:

   ```bash
   make       # builds with warnings
   make debug # builds with debug info
   ```

4. Run the program:

   ```bash
   ./program
   ```

5. Clean build files:

   ```bash
   make clean
   ```

---

## What I Verified

* **Exercise 5.1:** Manual dependencies (`main.o`, `functions.o`) compile correctly.
* **Exercise 5.2:** Automatic source detection works; `.d` dependency files trigger rebuilds when headers change; `debug` target includes symbols.

---

## Sources & AI Usage

* AI was used to assist in Makefile solutions and prepare this README.
---
