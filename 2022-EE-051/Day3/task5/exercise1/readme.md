# Exercise 5.1: Basic Makefile

## Objective

This exercise demonstrates how to compile a simple C program consisting of multiple source files (`main.c` and `functions.c`) using a **Makefile**. The Makefile automates compilation, linking, and cleanup.

---

## Project Structure

```
exercise1/
│── main.c
│── functions.c
│── functions.h
│── exercise1.mak
```
---

## 🔎 How the Makefile Works

* **all** → Default target, builds the final executable `program`.
* **program** → Links `main.o` and `functions.o` into one executable.
* **main.o / functions.o** → Compile each `.c` file into an object file.
* **clean** → Removes all generated files (`.o` and the executable).

This way you don’t need to manually compile each file with `gcc`.

---

## How to Compile & Run

1. **Compile the program**

   ```bash
   make -f exercise1.mak
   ```

2. **Run the program**

   ```bash
   ./program
   ```

3. **Clean build files**

   ```bash
   make -f exercise1.mak clean
   ```

---

## Verification

### 1. Build

```bash
$ make -f exercise1.mak
gcc -Wall -c main.c
gcc -Wall -c functions.c
gcc -o program main.o functions.o
```

### 2. Run

```bash
$ ./program
Hello
```

### 3. Clean

```bash
$ make -f exercise1.mak clean
rm -f program main.o functions.o
```
Everything worked correctly.

## Reference
- Slides
- AI
