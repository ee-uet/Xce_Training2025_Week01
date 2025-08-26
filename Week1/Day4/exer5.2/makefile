# Simple Makefile for calc project

CC = gcc
CFLAGS = -Wall -O2
DEBUGFLAGS = -g -Wall

# Find all .c files
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = calc

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compile each .c file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Debug target
debug: CFLAGS = $(DEBUGFLAGS)
debug: clean $(TARGET)

# Clean files
clean:
	rm -f $(OBJ) $(TARGET)

# Header dependencies
DEPS = $(SRC:.c=.d)
-include $(DEPS)

%.d: %.c
	$(CC) -MM $< -MF $@


