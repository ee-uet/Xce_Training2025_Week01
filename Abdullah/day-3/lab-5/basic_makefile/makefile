# Exercise 5.1: Basic Makefile
# Fixed: Changed spaces to TABS (critical fix)

CC = gcc
CFLAGS = -Wall

all: main
	./main

main: main.o
	$(CC) -o main main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f main.o main