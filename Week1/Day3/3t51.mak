CC = gcc
CFLAGS = -Wall

all: program

program: main.o hello.o
	$(CC) -o program main.o hello.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

hello.o: hello.c
	$(CC) $(CFLAGS) -c hello.c

clean:
	rm -f program main.o hello.o
