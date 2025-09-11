CC = gcc
CFLAGS = -Wall

# default target: build and run
all: sample
	@./sample

# link executable from object file
sample: sample.o
	$(CC) -o sample sample.o

# compile single source file into object
sample.o: sample.c
	$(CC) $(CFLAGS) -c sample.c

# clean build artifacts
clean:
	rm -f sample sample.o

