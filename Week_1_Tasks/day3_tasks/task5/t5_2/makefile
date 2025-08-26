CC := gcc
CFLAGS := -Wall
DEBUG := -Wall -g 
DEP := -MMD

EXE=out
CFILES := $(wildcard *.c)
OFILES := $(CFILES:.c=.o)
DFILES := $(CFILES:.c=.d)

all : $(EXE)
	@./$(EXE)

$(EXE) : $(OFILES)
	@$(CC) $(CFLAGS) $^ -o $@ 

%.o : %.c
	@$(CC) $(CFLAGS) $(DEP) $< -c -o $@

degug : CFLAGS=$(DEBUG)
debug : $(EXE)

clean : 
	@rm -f $(EXE) $(OFILES) $(DFILES)

-include $(DFILES)














	
