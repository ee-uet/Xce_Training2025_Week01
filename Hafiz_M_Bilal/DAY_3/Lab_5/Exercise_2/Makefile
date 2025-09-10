CC = gcc
CFLAGS= -Wall 
Debug_flag = -Wall -g
depend_flag = -MMD

source_files = $(wildcard *.c)
object_files = $(source_files:.c=.o)
depend_files = $(source_files:.c=.d)
executable   = E5_2

all: $(executable)

$(executable): $(object_files)
	@$(CC) $(CFLAGS) $^ -o $@ 

%.o: %.c
	@$(CC) $(CFLAGS) $(depend_flag) -c $< -o $@

-include $(depend_files)

debug: CFLAGS=$(Debug_flag) 
debug: clean $(executable)

run: $(executable)
	@./$(executable)

clean: 
	@rm -f $(executable) $(object_files) $(depend_files)

