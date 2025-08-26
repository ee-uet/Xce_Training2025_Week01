#all: program

#program: functions.o main.o 
#	gcc -o program main.o functions.o

#main.o: main.c
#	gcc -c -o main.o main.c

#functions.o: functions.c
#	gcc -c -o functions.o functions.c

#clean:
#	rm -f main.o functions.o program

################################################################

# Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c99
LDFLAGS =

# Automatic file detection
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

# Default target
all: program

# Main executable
program: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

# Debug target
debug: CFLAGS += -g
debug: program

# Compile object files and generate dependencies
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	@$(CC) $(CFLAGS) -MM -MP -MT '$@' -MF $(@:.o=.d) $<

# Include generated dependencies
-include $(DEPS)

# Clean target
clean:
	rm -f $(OBJS) $(DEPS) program

.PHONY: all debug clean