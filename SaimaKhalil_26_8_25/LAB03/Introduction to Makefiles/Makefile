# Compiler and flags
CC = gcc
CFLAGS = -Wall -g
TARGET = main

# Automatically find all C source files
SRCS = $(wildcard *.c)
# Generate object files from source files
OBJS = $(SRCS:.c=.o) #yni .c file ko .o file me lkh k expand krdya

# Default target
all: $(TARGET)

# Link object files to create executable
# gcc file.o -o file yni  ab executable ban jayega

$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
#gcc main.o file_operations.o text_processing.o -o main (main is executable file)
	

# Compile each .c into .o
# will works for any .c file
#rule to make a .o file from a .c file
# $< is the first prerequisite (the .c file)
# $@ is the target (the .o file)
#just compiling not linking
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@
#gcc -c main.c -o main.o

# Clean up
#-f means force, it will not prompt for confirmation
clean:
	rm -f $(OBJS) $(TARGET) *.d
