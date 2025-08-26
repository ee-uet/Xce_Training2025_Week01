CC = gcc
CFLAGS = -Wall

all: main
	./main.c

main: main.o
	$(CC) -o main.o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.o main.c

clean: 
	rm -f main main.o