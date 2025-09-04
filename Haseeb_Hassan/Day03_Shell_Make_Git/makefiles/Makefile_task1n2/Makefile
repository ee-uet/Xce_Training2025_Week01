CC = gcc
CFLAGS = -Wall
DEBUGFLAGS = -g -Wall

SRC = main.c functions.c
OBJ = $(SRC:.c=.o)
DEPS = functions.h


all: hello


hello: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

debug: CFLAGS = $(DEBUGFLAGS)
debug: clean hello


clean:
	rm -f hello $(OBJ)
#$@ means all target ....$< first dependencies............$^all dependencies