## Project Structure

```
Lab5/
├── README.md
├── Part1/
│   ├── Makefile           # Basic C project Makefile
│   ├── main.c             # Main C source file
│   └── function.c         # Function definitions
├── Part2/
│   ├── Makefile           # Advanced C project Makefile
│   ├── main.c             # Main C source file
│   └── function.c         # Function definitions
└── Part3/
    ├──INSTALL_DIR/        # Directory where to install scripts
    ├── Makefile           # Shell script project Makefile
    ├── my_script1.sh      # Sample shell script 1
    ├── my_script2.sh      # Sample shell script 2
    └── tests/
        └── test_myscript1.sh      # Unit test files
        └── test_myscript2.sh 
```

## Exercises Overview

### Exercise 5.1: Basic Makefile
**Purpose**: Create a simple Makefile for compiling C programs
**Features**:
- Compiles `main.c` and `function.c` into executable
- Separate compilation of object files
- Clean target for removing build artifacts

### Exercise 5.2: Advanced Makefile
**Purpose**: Demonstrate advanced Makefile features
**Features**:
- Automatic handling of multiple source files
- Debug target with debugging symbols
- Dependency tracking for header files
- Pattern rules and variables

### Exercise 5.3: Shell Script Makefile
**Purpose**: Manage shell script projects with Makefile
**Features**:
- Syntax checking for shell scripts
- Unit test execution
- Script installation to specified directory

## How to Use

### Exercise 5.1: Basic C Compilation

```bash
cd Exercise_5.1/

# Compile the project
make

# Or explicitly use 'all' target
make all

# Clean build artifacts
make clean

# Compile individual components
make main.o
make function.o
```

### Exercise 5.2: Advanced C Compilation

```bash
cd Exercise_5.2/

# Standard compilation
make

# Debug build with symbols
make debug

# Clean all files including dependencies
make clean

# Check dependencies (automatic)
make main
```

### Exercise 5.3: Shell Script Management

```bash
cd Exercise_5.3/

# Check syntax of all scripts
make check

# Run all tests
make test

# Install scripts to directory
make install

# Clean temporary files
make clean
```

## Makefile Features Explained

### Basic Makefile (Exercise 5.1)
- **Explicit Rules**: Each target explicitly defined
- **Simple Dependencies**: Direct file-to-file relationships
- **Manual Object File Creation**: Individual rules for each .o file

### Advanced Makefile (Exercise 5.2)
- **Variables**: `CC`, `CFLAGS`, `TARGET`, `SRCS`, `OBJS`
- **Pattern Rules**: `%.o: %.c` for automatic compilation
- **Dependency Generation**: Automatic header dependency tracking
- **Conditional Compilation**: Debug flags added conditionally

### Shell Script Makefile (Exercise 5.3)
- **Wildcard Functions**: Automatic test file discovery
- **Shell Commands**: Bash syntax checking and test execution
- **Installation**: Script deployment to target directory
- **Error Handling**: Exit on first failure

## Key Concepts Demonstrated

### Make Variables
```makefile
CC = gcc                    # Compiler variable
CFLAGS = -Wall -Wextra     # Compiler flags
SRCS = main.c function.c   # Source files list
```

### Pattern Rules
```makefile
%.o: %.c                   # Any .o file depends on corresponding .c file
	$(CC) $(CFLAGS) -c $< -o $@
```

### Automatic Variables
- `$@` - Target name
- `$<` - First prerequisite
- `$^` - All prerequisites

### Dependency Tracking
```makefile
-MMD -MP                   # Generate dependency files
-include $(DEPS)           # Include dependency files
```

## Common Make Commands

| Command        | Description                          |
|----------------|--------------------------------------|
| `make`         | Build default target (usually 'all') |
| `make clean`   | Remove build artifacts               |
| `make debug`   | Build with debug symbols             |
| `make install` | Install to target directory          |
| `make -n`      | Show commands without executing      |
| `make -j4`     | Parallel build with 4 jobs           |

## Prerequisites

### For C Projects:
- GCC compiler
- Make utility
- C source files

### For Shell Script Projects:
- Bash shell
- Make utility
- Write permissions for installation directory

## Error Handling

All Makefiles include proper error handling:
- Syntax errors stop the build process
- Failed tests prevent installation
- Missing files are reported clearly
- Clean targets safely remove only generated files

## Customization

### Changing Compiler Flags
```makefile
# Edit CFLAGS in Exercise 5.2
CFLAGS = -Wall -Wextra -std=c99 -pedantic
```

### Adding New Scripts
```makefile
# Edit SCRIPTS variable in Exercise 5.3
SCRIPTS = script1.sh script2.sh new_script.sh
```

### Changing Install Directory
```makefile
# Modify INSTALL_DIR in Exercise 5.3
INSTALL_DIR = /usr/local/bin
```
