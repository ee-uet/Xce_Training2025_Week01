# Lab Experiment – Introduction to Makefiles

### Exercise 5.1: Basic Makefile
```
all: calc

calc: main.o add.o product.o
        gcc main.o add.o product.o -o calc

main.o: main.c
        gcc -c main.c

add.o: add.c
        gcc -c add.c

product.o: product.c
        gcc -c product.c

clean:
        rm -f *.o calc
```
### Exercise 5.2: Advanced Makefile
```
```
### Exercise 5.3: Advanced Makefile
```
```