# Task 5.1 Simple Makefile

This project demonstrates how to compile and link multiple C source files using a **Makefile**. The project consists of `main.c` and `function.c` with their header `function.h`.

---

##  Makefile Overview

**Compiler and Flags**
```makefile
CC = gcc
CFLAGS = -Wall -g
```
CC  :  C compiler (gcc)
CFLAGS  :
    -Wall : Enable all compiler warnings
    -g : Include debugging information

**Target Executable**
```makefile
TARGET = main
```
the final executable file is named main.

**Object Files**
```makefile
OBJS = main.o function.o
```
the source files are   compiled into object files (.o)
and then linked together to produce the executable.

**Default Target**
```makefile
all: $(TARGET)
```
This is default target when we run make.

**Linking Object Files**
```markdown
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
```
this combines all object files into the executable main.
This equals:
```markdown
gcc -Wall -g -o main main.o function.o
```
**Compiling Source Files**
```markdown
main.o: main.c function.h
	$(CC) $(CFLAGS) -c main.c
function.o: function.c function.h
	$(CC) $(CFLAGS) -c function.c
```
this compile .c source files into .o object files
Header dependencies are ensuring recompilation when needed.

**Clean Build Artifacts**
```markdown
clean:
	rm -f $(OBJS) $(TARGET)
```
this removes object files and executable.

---

**Compile and Build Executable**
```bash
**make**
```
Run the program
```bash
./main
```