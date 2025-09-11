CC = gcc
CFLAGS = -Wall

all: hello

hello: main.o function.o
	$(CC) -o hello function.o main.o

function.o: function.c
	$(CC) $(CFLAGS) -c function.c 

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c

clean: 
	rm -f hello function.o main.o
