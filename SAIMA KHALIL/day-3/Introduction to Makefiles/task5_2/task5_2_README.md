## Task 5.2 — Simple Makefile Project

This project demonstrates how to compile and link multiple **C source files** into a single executable using a **Makefile**.  
The project typically consists of:

- `main.c` : contains the `main()` function  
- `function.c` : implementation of helper functions  
- `function.h` : header file with function declarations  

---

### Makefile Overview

**Compiler and Flags**
```makefile
CC = gcc
CFLAGS = -Wall -g
CC : C compiler (gcc)

CFLAGS : Compiler options

-Wall : Enable all warnings
```

-g : Include debugging symbols

**Target Executable**
```makefile
TARGET = main
```
The final compiled program is named main.

**Source and Object Files**
```makefile
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
```

SRCS : Expands to all .c files in the directory (main.c function.c).
OBJS : Converts .c files into .o object files (main.o function.o).

**Default Target**
```makefile
all: $(TARGET)
```
The default target is all, which builds the executable.
Running just make will trigger this rule.

**Linking Object Files**
```makefile
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
```
Links all object files into a single executable.

Thus equivalent to:
```makefile
gcc -Wall -g -o main main.o function.o
```

**Compiling Source Files**
```makefile
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@
```
Compiles each .c file into a .o file
```makefile
$< means the first dependency (the .c file).
$@ means the target file (the .o file).
```
Header file dependency here is ensuring recompilation incase function.h changes.

**Cleaning Build **
```makefile
clean:
	rm -f $(OBJS) $(TARGET) *.d
```
Removes all object files, executable, and dependency files.

####   Build and Run

**Build the Project**
```bash
make
```

**Run the Executable**
```bash
./main
```

**Clean Build Files**
```bash
make clean
```