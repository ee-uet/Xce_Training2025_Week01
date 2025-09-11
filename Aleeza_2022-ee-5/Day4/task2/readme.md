# Advanced Makefile Project

The goal of this project is to extend previous basic Makefile to automatically handle multiple source files, include debugging support, and track header file dependencies.

## Approach 
1. **Source Files**  
    - All `.c` files in the project directory (e.g., `main.c`, `add.c`, `product.c`).  
    - Object files (`.o`) are generated automatically for each source file using pattern rules.  

2. **Header Files**  
    - Any `.h` files included in the sources are tracked for changes.  
    - Dependency files (`.d`) are automatically generated for each source to track which headers each source depends on.  

3. **Makefile**  
    - The Makefile automatically finds all `.c` files using `wildcard`.  
    - Targets:
        - `all` : Builds the main executable (`calc`) by compiling all object files.  
        - `%.o` : Pattern rule to compile any `.c` file into an object file with default compiler flags.  
        - `%.d` : Generates dependency files for header tracking.  
        - `debug` : Rebuilds the project with debugging symbols (`-g -Wall`).  
        - `clean` : Deletes all object files, dependency files, and the executable for a fresh build.  

4. **Compiler Flags**  
    - `CFLAGS` : `-Wall -O2` (default build).  
    - `DEBUGFLAGS` : `-g -Wall` (for debug build).  
    - `CC` : Compiler used (`gcc`).  

## How to Run
1. Open a terminal in the project directory.  
2. Run `make` to compile all source files and generate the executable `calc`.  
3. Run the program using `./calc`.  
4. To build with debugging symbols, run `make debug`.  
5. To remove all object files, dependency files, and the executable, run `make clean`.  

## Known Limitations
- Assumes all source files are in the same directory as the Makefile.    

## Sources & AI Usage
- Information about automatic dependency tracking and Makefile pattern rules - `ChatGPT`  
- AI was consulted to format explanations and clarify debugging flags usage - `ChatGPT`

