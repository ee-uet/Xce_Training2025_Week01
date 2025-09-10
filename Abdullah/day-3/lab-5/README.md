# Lab 5: Introduction to Makefiles

## Problem
1. **Basic Makefile (Exercise 5.1)**: Create a simple Makefile for C program compilation with basic targets
2. **Advanced Makefile (Exercise 5.2)**: Extend Makefile with automatic source detection, debug builds, and dependency tracking
3. **Script Makefile (Exercise 5.3)**: Create Makefile for shell script project with syntax checking and installation

## Approach

### Basic Makefile
1. Define compiler and flags variables
2. Create targets for compilation (all, main, main.o)
3. Add clean target for removing generated files
4. Use proper makefile syntax with tabs

### Advanced Makefile
1. Use wildcard patterns for automatic source detection
2. Implement pattern rules for object file generation
3. Add dependency tracking with .d files
4. Create debug target with debug symbols

### Script Makefile
1. Define shell script validation using bash -n
2. Implement test running capability
3. Create installation target with proper permissions
4. Use PHONY targets for non-file targets

## How to Run

### Basic Makefile
```bash
cd basic_makefile/
make          # Compile and run
make clean    # Remove generated files
```

### Advanced Makefile
```bash
cd advanced_makefile/
make          # Compile with standard flags
make debug    # Compile with debug symbols
make clean    # Remove all generated files
```

### Script Makefile
```bash
cd script_makefile/
make check    # Check script syntax
make test     # Run tests
make install  # Install scripts
make clean    # Clean project
```

## Example Output

### Basic Makefile
```bash
$ make
gcc -Wall -c main.c
gcc -o main main.o
./main
Hello from main!
```

### Advanced Makefile
```bash
$ make debug
rm -f main.o main.d main
gcc -Wall -g -MMD -c -o main.o main.c
gcc -Wall -g -o main main.o
```

### Script Makefile
```bash
$ make check
Checking scripts/hello.sh
Checking scripts/backup.sh
All scripts passed syntax check
```

## Design Notes
- All makefiles use tabs for indentation (critical requirement)
- Variables defined for compiler and flags for maintainability
- Pattern rules used for scalability
- PHONY targets properly declared

## Key Concepts Demonstrated
- **Makefile Syntax**: Proper target:dependency format with tab indentation
- **Variables**: CC, CFLAGS for maintainable configuration
- **Pattern Rules**: %.o: %.c for automatic compilation
- **Dependency Tracking**: .d files for header dependencies
- **Wildcard Expansion**: $(wildcard *.c) for source detection
- **PHONY Targets**: Non-file targets like clean, debug, test

## Critical Error Corrections Made
- **Fixed tab indentation**: Original used spaces instead of tabs (fatal error)
- **Corrected syntax errors**: Fixed backslash placement in script makefile
- **Added PHONY declarations**: Properly declared non-file targets
- **Improved variable naming**: Used consistent naming conventions
- **Enhanced error handling**: Better dependency management

## Assumptions & Edge Cases
- Assumes GCC compiler availability
- Source files follow standard C naming conventions
- Scripts located in scripts/ directory for script makefile
- Installation directory permissions properly set

## Known Limitations
- Basic makefile hardcodes source file names
- No error handling for missing compiler
- Script makefile assumes specific directory structure
- Limited cross-platform compatibility

## Makefile Best Practices Demonstrated
1. **Use variables** for compiler and flags
2. **Proper indentation** with tabs (not spaces)
3. **Dependency tracking** for efficient rebuilds
4. **Clean targets** for project maintenance
5. **PHONY targets** for non-file operations
6. **Pattern rules** for scalability
7. **Wildcard usage** for automatic source detection

## Sources & AI Usage
- Original template code from lab manual
- Standard makefile patterns and best practices
- GNU Make documentation references