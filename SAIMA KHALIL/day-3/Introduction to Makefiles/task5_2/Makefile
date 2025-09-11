
CC = gcc
CFLAGS = -Wall -g
TARGET = main

SRCS = $(wildcard *.c)
 
OBJS = $(SRCS:.c=.o)  

all: $(TARGET)
 
$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
 
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	rm -f $(OBJS) $(TARGET) *.d
