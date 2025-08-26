# Yeh ek advance Makefile hai kaam asaan karega!
SOURCES = main.c functions.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = my_program
all: $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	gcc $(OBJECTS) -o $@
%.o: %.c
	gcc -c $<
debug: CFLAGS = -g -DDEBUG
debug: $(EXECUTABLE)

# Sab kuch saaf karne ke liye 'clean' target
clean:
	rm -f $(EXECUTABLE) $(OBJECTS)