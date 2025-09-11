CC = gcc
CFLAGS = -Wall

all: program

program: main.o functions.o
	$(CC) -o program main.o functions.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

functions.o: functions.c
	$(CC) $(CFLAGS) -c functions.c

clean:
	rm -f program main.o functions.o
