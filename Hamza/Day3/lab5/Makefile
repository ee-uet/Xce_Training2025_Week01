# Target for the final executable
all: program

# Rule to create the final executable from object files
program: main.o functions.o
	gcc main.o functions.o -o program

# Rule to compile main.c into main.o
main.o: main.c
	gcc -c main.c

# Rule to compile functions.c into functions.o
functions.o: functions.c
	gcc -c functions.c

# Rule to clean up generated files
clean:
	rm -f program *.o