CC = gcc
CFLAGS = -Wall

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
TRGT = program

all: $(TRGT)

$(TRGT): $(OBJS)
	@echo "building executable..."
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@echo "compiling file $< ..."
	$(CC) $(CFLAGS) -c $< -o $@

%.d: %.c
	$(CC) -MM $(CFLAGS) $< > $@

-include $(DEPS)

debug: CFLAGS += -g
debug: $(TRGT)

clean:
	rm -f $(OBJS) $(DEPS) $(TRGT)

