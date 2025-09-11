CC = gcc
CFLAGS = -Wall -O2
DEBUG_FLAGS = -g -Wall

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
TARGET = myprogram

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

%.o: %.c
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean $(TARGET)

-include $(OBJS:.o=.d)

clean:
	rm -f $(OBJS) $(TARGET) *.d
