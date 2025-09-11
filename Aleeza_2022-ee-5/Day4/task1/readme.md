# Basic Makefile Project

The goal of this project is to create a simple C program that demonstrates how to organize multiple source files and compile them into an executable using a Makefile.
## Approach 
1. **Source Files**  
    - `main.c` : Contains the `main` function which uses the functions defined in other files.  
    - `add.c`  : Implements a function to add two numbers.  
    - `product.c` : Implements a function to calculate the product of two numbers.  

2. **Header File**  
    - `functions.h` : Contains the declarations of `add` and `product` functions. This header is included in `main.c` to allow the `main` function to use these functions.  

3. **Makefile**  
    - The Makefile is used to compile the program in an organized way.  
    - Targets:
        - `all` : Builds the main executable `calc`.  
        - `calc` : Links all object files (`main.o`, `add.o`, `product.o`) into the executable.  
        - Individual object file targets (`main.o`, `add.o`, `product.o`) : Compile corresponding source files into object files.  
        - `clean` : Deletes all object files and the executable to allow a fresh build.  


## How to Run
1. Open a terminal in the project directory.  
2. Run `make` to compile all files and create the executable `calc`.  
3. Run the program with `./calc`.  
4. To clean up object files and the executable, run `make clean`.  

## Known Limitations
- The program currently only handles integer addition and multiplication.  
- No error handling for invalid inputs.  

## Sources & AI Usage
- Information about header file - `ChatGPT`
- AI was consulted to confirm Makefile structure - `ChatGPT`