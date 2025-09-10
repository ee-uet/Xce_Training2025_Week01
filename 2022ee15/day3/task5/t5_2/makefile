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
# link object files into executable
$(EXE) : $(OFILES)
	@$(CC) $(CFLAGS) $^ -o $@ 
# compile rule that also generates dependency file
%.o : %.c
	@$(CC) $(CFLAGS) $(DEP) $< -c -o $@
# debug target: compile with debug flags
debug : CFLAGS=$(DEBUG)
debug : $(EXE)
# clean build and dependency files
clean : 
	@rm -f $(EXE) $(OFILES) $(DFILES)
# include auto-generated dependency files if present
-include $(DFILES)














	
