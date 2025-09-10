# Exercise 5.2: Advanced Makefile

CC = gcc
CFLAGS = -Wall 
DEBUGCFLAGS = -Wall -g

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

TARGET = main

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

# Debug build
debug: CFLAGS = $(DEBUGCFLAGS)
debug: clean $(TARGET)

clean: 
	rm -f $(OBJECTS) $(DEPS) $(TARGET)

# Include dependency files if they exist
-include $(DEPS)

.PHONY: clean debug