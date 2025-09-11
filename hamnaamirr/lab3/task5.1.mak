CC = gcc
CFLAGS = -Wall
TARGET = program
OBJS = main.o function.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

function.o: function.c
	$(CC) $(CFLAGS) -c function.c

clean:
	rm -f $(TARGET) $(OBJS)
