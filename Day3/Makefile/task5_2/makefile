CC = gcc
CFLAGS = -Wall 
DEBUGCFLAGS = -Wall -g

source = $(wildcard *.c)
object = $(source:.c=.o)
deps   = $(source:.c=.d)

target = main

$(target): $(object)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

# Debug build
debug: CFLAGS = $(DEBUGCFLAGS)
debug: clean $(target)

clean: 
	rm -f $(object) $(deps) $(target)

# Include dependency files if they exist
-include $(deps)
