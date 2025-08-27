# Variables
CC = gcc
CFLAGS = -Wall -O2
SRC = bitops.c
EXE = bitops
TEST_SCRIPT = run_tests.sh

.PHONY: all build test clean

# Default target
all: build

# Compile the C program
build:
	$(CC) $(CFLAGS) -o $(EXE) $(SRC)

# Run the tests using the bash script
test: build
	./$(TEST_SCRIPT)

# Remove executable and any temp files
clean:
	rm -f $(EXE)
