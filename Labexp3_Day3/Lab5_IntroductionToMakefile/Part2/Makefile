# C Project Makefile
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2
DEBUGFLAGS = -g

# Project files
TARGET = main
SRCS = main.c function.c
OBJS = $(SRCS:.c=.o)           # Convert .c to .o files
DEPS = $(SRCS:.c=.d)           # Dependency files

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files with dependency generation
%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Debug build with debug flags
debug: CFLAGS += $(DEBUGFLAGS)
debug: clean $(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)

# Include dependency files
-include $(DEPS)
