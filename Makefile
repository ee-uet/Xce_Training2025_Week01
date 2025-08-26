# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -O2
DEBUGFLAGS = -g
TARGET = main
SRCS = main.c function.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
debug: CFLAGS += $(DEBUGFLAGS)
debug: clean $(TARGET)
clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)
-include $(DEPS)
