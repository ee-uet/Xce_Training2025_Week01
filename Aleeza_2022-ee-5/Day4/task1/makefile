# Default target when we just run make
all: calc

# Link object files to create the final executable 'calc'
calc: main.o add.o product.o
        # Compile all object files into the executable
	gcc main.o add.o product.o -o calc

# Compile main.c into main.o
main.o: main.c
	gcc -c main.c

# Compile add.c into add.o
add.o: add.c
	gcc -c add.c

# Compile product.c into product.o
product.o: product.c
	gcc -c product.c

# Clean target to remove compiled files
clean:
        # Remove all object files and the executable
	rm -f *.o calc
