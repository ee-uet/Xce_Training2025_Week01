# Day-05: RISC-V ISA & Spike – Lab Guide

This directory contains RISC-V assembly exercises and a Makefile for building and running programs using the Spike simulator.

---

## Folder Structure

- `problems/`
	- `calculator.s` – RISC-V assembly source for calculator
	- `factorial.s` – RISC-V assembly source for factorial
	- `set_bit.s` – RISC-V assembly source for bit manipulation
	- `link.ld` – Linker script
	- `makefile` – Build and run automation

---

## How to Build and Run RISC-V Assembly Programs

1. **Navigate to the `problems` folder**
	 - Example: `cd problems`

2. **Edit the Makefile to select the program to build**
	 - Open `makefile` in a text editor.
	 - Change the value of `PROG` to the name of the program you want to build (without `.s`).
		 - Example: To build `calculator.s`, set `PROG=calculator`

3. **Build the program**
	 - Run:
		 ```sh
		 make
		 ```
	 - This will assemble and link the selected program, producing an executable (e.g., `factorial`, `calculator`).

4. **Run the program with Spike**
	 - Run:
		 ```sh
		 make run
		 ```
	 - This will execute the program in the Spike RISC-V simulator.

5. **Debug the program with Spike**
	 - Run:
		 ```sh
		 make debug
		 ```
	 - This will run Spike in debug mode with commit logs.

6. **Clean build files**
	 - Run:
		 ```sh
		 make clean
		 ```
	 - This will remove object files and executables.

---

## Notes

- Make sure you have the RISC-V toolchain (`riscv64-unknown-elf-as`, `riscv64-unknown-elf-ld`) and Spike simulator installed.
- Only one program can be built at a time; change `PROG` in the Makefile as needed.
- Output and any generated files will be created in the `problems` folder.
- For custom linker scripts, ensure `link.ld` is present and correctly configured.

---

**Tip:** Explore each assembly source file to understand its functionality. You can modify and rerun them to experiment further.
