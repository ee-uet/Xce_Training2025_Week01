
---

# RISC-V Assembly – Makefile Usage

This repository provides a `Makefile` to build and run RISC-V assembly programs using the **GNU RISC-V toolchain** and the **Spike simulator**.
All assembly source files (`.S`) are located inside subfolders.

---

## How to Use

### 1. Build a Program

Each program is built by specifying its path (without the `.S` extension) as the `PROG` variable:

```bash
make PROG=folder/filename
```

Example:

```bash
make PROG=abs/abs_diff
```

---

### 2. Run with Spike

```bash
make run PROG=folder/filename
```

Example:

```bash
make run PROG=abs/abs_diff
```

---

### 3. Debug with Spike

```bash
make debug PROG=folder/filename
```

This opens Spike in debugger mode (`-d --log-commits`).

---

### 4. Clean Build Artifacts

```bash
make clean PROG=folder/filename
```

This removes the `.o` file and executable.

---

## Notes

* Always pass `PROG=dir/name` **without `.S` extension**.
* Requires `link.ld` linker script in the project root.
* Programs will only run if you have installed:

  * **RISC-V GNU toolchain** (`riscv64-unknown-elf-*`)
  * **Spike simulator**

---
