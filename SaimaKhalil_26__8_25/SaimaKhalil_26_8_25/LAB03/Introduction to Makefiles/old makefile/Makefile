# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Target executable
TARGET = main

# Object files
OBJS = main.o function.o

# Default target
all: $(TARGET)

# Link object files into final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
#gcc  Walls -g -o main main.o function.o (executable file=main here)

# Compile .c to .o
main.o: main.c function.h
	$(CC) $(CFLAGS) -c main.c

function.o: function.c function.h
	$(CC) $(CFLAGS) -c function.c

# Remove build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
