# Muhammad_Boota Training Labs – Comprehensive Guide

This folder contains a series of programming labs for C language basics, advanced C, Bash scripting, Makefile usage, Git, and RISC-V assembly. Each day covers different topics and includes code, scripts, and supporting documents. Below is a guide for navigating and running all tasks.

---

## Folder Overview

- **Day-01_ Orientation & C-language basics/**
  - C programming basics: data types, control flow, file I/O, bitwise operations, enums, structs, command-line arguments.
  - Main file: `template_code_Part0.c`
  - Supporting files: `integerfile.txt`, `makefile`, documentation PDFs.

- **Day-02_ C-language Advanced/**
  - Advanced C: pointers, arrays, custom string functions, macros, structs, file I/O, linked lists, dynamic memory, Booth's multiplication.
  - Main file: `template_code_Day2.c`
  - Supporting files: `student.txt`, documentation PDFs.

- **Day-03_ MakeFile, Git & Bash/**
  - Bash scripting and C projects with Makefiles.
  - Labs:
    - `lab1/` – Basic Bash scripts
    - `lab2/` – Bash control flow
    - `lab3/` – Arrays and functions in Bash
    - `lab4/` – Backup, counting, logging scripts
    - `lab5/` – C projects with Makefiles

- **Day-04_ TCL Scripting/**
  - TCL scripting exercises and documentation.

- **Day-05 RISCV ISA & Spike/**
  - RISC-V assembly programming and simulation with Spike.
  - Main folder: `problems/` (assembly sources, linker script, Makefile)

---

## How to Run C Code (Day-01 & Day-02)

1. **Select the Task(s) to Run**
   - Open the main C file (`template_code_Part0.c` or `template_code_Day2.c`).
   - Uncomment the function calls in `main()` for the tasks you want to run.
2. **Build the Code**
   - Open a terminal in the folder.
   - Run:
     ```sh
     make
     ```
3. **Run the Program**
   - Run:
     ```sh
     ./main.exe
     ```
   - (Or `./main` on Linux/Mac)
4. **User Input**
   - Day-01: Some tasks require user input (calculator, guessing game, Fibonacci, etc.).
   - Day-02: Most tasks use hardcoded values; no user input required.
5. **Output**
   - Output is printed in the terminal. File I/O tasks create files in the same directory.

---

## How to Run Bash Scripts (Day-03)

1. **Navigate to the desired lab folder**
   - Example: `cd lab1`
2. **Give execute permission**
   - Run:
     ```sh
     chmod +x scriptname.sh
     ```
3. **Run the script**
   - Run:
     ```sh
     ./scriptname.sh
     ```
   - Some scripts require arguments (see script for details).

---

## How to Run C Projects with Makefile (Day-03/lab5)

1. **Navigate to the subfolder**
   - Example: `cd lab5/lab1`
2. **Build and run**
   - Run:
     ```sh
     make
     ./main.exe
     ```

---

## How to Run RISC-V Assembly (Day-05)

1. **Navigate to `problems/` folder**
2. **Edit the Makefile**
   - Set `PROG` to the desired program (e.g., `factorial`, `calculator`).
3. **Build the program**
   - Run:
     ```sh
     make
     ```
4. **Run with Spike**
   - Run:
     ```sh
     make run
     ```
5. **Debug with Spike**
   - Run:
     ```sh
     make debug
     ```
6. **Clean build files**
   - Run:
     ```sh
     make clean
     ```

---

## Notes

- For Bash scripts, always use `chmod +x` before running.
- For C and assembly, ensure you have the required compilers and simulators installed.
- Output and generated files are created in the respective folders.
- Documentation and lab instructions are available in the `docx/` subfolders.

---

**Tip:** Explore each script and code file to understand its functionality. Modify and rerun to experiment and learn.
