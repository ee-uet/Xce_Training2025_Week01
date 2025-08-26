CC=gcc
CFLAGS= -Wall
all:sample
	@./sample
sample: sample.o
	$(CC) -o sample sample.o

sample.o: sample.c 
	$(CC) $(CFLAGS) -c sample.c

clean:
	rm -f sample sample.o
