CC = gcc
CFLAGS = -Wall -O2
DEBUGFLAGS = -g -Wall
TARGET = calc

# Find all source and object files
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

# Default target
all: $(TARGET)

# Link objects into executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

# Compile rule (normal build)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Generate dependency files
%.d: %.c
	$(CC) -MM $< -MF $@  # -MM: make header dependency list. -MF: save output to .d file

-include $(DEPS)

# Debug build (rebuild with debug flags)
debug: CFLAGS = $(DEBUGFLAGS)
debug: clean $(TARGET)

# Clean build files
clean:
	rm -f $(OBJ) $(DEPS) $(TARGET)

