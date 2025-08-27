# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Target executable
TARGET = myprogram

# Source files
SOURCES = main.c functions.c

# Object files
OBJECTS = main.o functions.o

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Compile main.c
main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c

# Compile functions.c
functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

# Clean up build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Declare phony targets
.PHONY: all clean