# Problem
- Create a simple C program with a main.c and functions.c
- Write a Makefile to compile these into an executable.
- Include targets for 'all', 'clean', and individual object files.
#
**Approach**  

- Compiler Setup

    CC = gcc;  specifies the compiler to use.

-  CFLAGS = -Wall;  ensures all warnings are shown during compilation.

- Main Target (all)

   - The all target is set to build the executable named hello.

- Building the Executable (hello)

  - The target hello depends on main.o and function.o.

  - These object files are linked together using GCC to create the final executable.

- Compiling Individual Files

   - main.c is compiled into main.o.

   - function.c is compiled into function.o.

   - At this stage, only object files are created, not the full program.

- Cleaning Up

  - The clean target removes the executable and object files (hello, main.o, function.o).

  - This ensures a fresh build can be done without leftover files.
#
**How to run**
1. Open Terminal in the folder where main.c, function.c, and Makefile are saved.
2. Build the Program by typing make on the terminal.
  This will compile main.c and function.c into object files. Then link them together to create the executable hello. 
3. Run the Executable  

   ./hello
4. Clean the Build Files  
  'make clean'  
This removes hello, main.o, and function.o so a fresh build can be done.
#
**Example**  
Output after running make command on the terminal:  
gcc -Wall -c main.c
gcc -Wall -c function.c 
gcc -o hello function.o main.o  
After running the executable file, gets the final output:  
sum = 8  
#
**Known limitations**  
This Makefile is not fully generalized. Every time a new source file is added or the file names are changed, the Makefile must be updated manually to include those files.
#
**Verification / What I Learned**  
 I understood the syntax and working of the script using the lab slides.