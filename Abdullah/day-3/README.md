# Shell Scripting & Makefile Lab

This repository contains solutions for Shell Scripting and Makefile exercises covering basic to advanced topics in Linux shell programming and build automation.

## Project Structure

```
/shell-lab/
├── README.md                    # This file
├── lab-1/                       # Basic Shell Scripting
│   ├── hello.sh
│   ├── user_input.sh
│   ├── command_args.sh
│   └── README.md
├── lab-2/                       # Control Structures
│   ├── even_odd.sh
│   ├── multiples.sh
│   ├── guessing_game.sh
│   └── README.md
├── lab-3/                       # Functions and Arrays
│   ├── factorial.sh
│   ├── array_fruits.sh
│   ├── associative_arrays.sh
│   └── README.md
├── lab-4/                       # File Operations
│   ├── file_reading.sh
│   ├── text_processing.sh
│   ├── backup_script.sh
│   └── README.md
└── lab-5/                       # Makefiles
    ├── basic_makefile/
    │   ├── Makefile
    │   ├── main.c
    │   └── functions.c
    ├── advanced_makefile/
    │   ├── Makefile
    │   └── README.md
    ├── script_makefile/
    │   ├── Makefile
    │   ├── scripts/
    │   └── tests/
    └── README.md
```

## Lab Objectives

This lab manual provides hands-on experience with:
- Linux Shell scripting fundamentals
- Control structures (if-else, loops)
- Functions and array manipulation
- File operations and text processing
- Makefile creation and build automation

## Prerequisites

- Basic understanding of Linux commands
- Access to a Linux environment (VM or WSL on Windows)
- Text editor (nano, vim, or gedit)

## How to Use

1. Navigate to each lab folder
2. Read the specific README for instructions
3. Make scripts executable: `chmod +x script_name.sh`
4. Run scripts: `./script_name.sh`
5. For makefiles: `make` or `make target_name`

## Key Concepts Covered

### Shell Scripting
- **Variables and Input**: User interaction and data storage
- **Command-line Arguments**: Processing script parameters
- **Control Flow**: Conditional statements and loops
- **Functions**: Code organization and reusability
- **Arrays**: Data structure manipulation
- **File Operations**: Reading, writing, and processing files
- **Text Processing**: Log analysis and data extraction

### Makefiles
- **Basic Targets**: Compilation and cleanup
- **Dependency Management**: Automatic rebuilding
- **Pattern Rules**: Generic compilation rules
- **Advanced Features**: Debug builds, automatic source detection
- **Script Integration**: Syntax checking and testing
- **Phony Targets**: Non-file targets for tasks

## Sources & AI Usage

- Official documentation and tutorials provided in lab manual
- Online forums and communities
- AI assistance for code optimization and new syntax suggestions