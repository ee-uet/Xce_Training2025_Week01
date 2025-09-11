# Problem
-  Extend the previous Makefile to handle multiple source files automatically
- Add a 'debug' target that compiles with debugging symbols
   Implement dependency tracking for header files
#
**Approach**  

1. Variables

   - CC = gcc; Compiler used is GCC.

   - CFLAGS = -Wall -g -MMD -MP ; Options passed to the compiler:

   - -Wall  Show all warnings.

    - -g ; Include debugging info.

   - -MMD -MP ; Generate dependency files (helps track header changes).

- source_files = $(wildcard *.c) ; Finds all .c files automatically in the folder.

- object_files = $(source_files:.c=.o) ; Converts every .c file into its .o (object) file form.

- dep_files = $(object_files:.o=.d) ; Creates .d dependency files for each .o.

- final = program ; Name of the final executable file.
2. Targets and Rules

   - all: $(final)
     Default rule, builds the program.

   - $(final): $(object_files)
      Links all object files into the final executable.    
      $@ means the target (program).  
      $^ means all dependencies (all .o files).  

   - %.o: %.c
       A pattern rule to compile each .c file into a .o file.
       $< means the first dependency (the .c file).
       $@ means the target (the .o file).

   - debug: CFLAGS += -g
     Builds the program with debug info.
     First cleans old files, then recompiles.

   - clean:
     Deletes the final program, all .o, and .d files. Keeps the folder clean.

3. Dependencies

    include $(dep_files)  
  Includes dependency files so if a header changes, only the required .c files get recompiled.
#
**How to run**
1. Open Terminal in the folder where C files and Makefile are saved.
2. Build the Program by typing make on the terminal.
  This will compile C files into object files. Then link them together to create the executable hello. 
3. Run the Executable  

   ./Program
4. Clean the Build Files  
  'make clean'  
#
**Example**  
Output after running make command on the terminal:  
gcc -Wall -g -MMD -MP -c function.c -o function.o
gcc -Wall -g -MMD -MP -c main.c -o main.o
gcc -o program function.o main.o
After running the executable file, gets the final output:  
sum = 8  
#
**Verification / What I Learned**  
-  I understood the syntax and working of the script using the lab slides.
- I learned about the concept of dependencies in Makefiles from AI. Specifically, I understood how -MMD and -MP help in keeping track of header files. This means when a header file changes, the related .c files are recompiled automatically, so the program always stays up to date.