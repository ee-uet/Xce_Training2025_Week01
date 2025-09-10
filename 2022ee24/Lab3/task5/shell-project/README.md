
---

# Shell Scripting Exercises – Part 5.3

This repository contains a **Makefile** designed to manage a project with multiple shell scripts. It provides automation for syntax checking, unit testing, and installation of scripts.

---

## Exercise 5.3: Makefile for a Shell Script Project

### Problem

* Create a project with multiple shell scripts.
* Write a Makefile that:

  1. Checks scripts for syntax errors.
  2. Runs unit tests (if available).
  3. Installs scripts to a specified directory.

---

### Approach

* **Scripts Directory:** All scripts are stored inside `scripts/`.
* **Tests Directory:** Optional unit tests can be placed inside `tests/`.
* **Binary Directory:** Scripts are installed into `bin/` for easy execution.
* **Key Targets in Makefile:**

  * `make check`: Runs `bash -n` on all scripts to detect syntax errors.
  * `make test`: Runs all test scripts inside `tests/` (if available).
  * `make install`: Installs scripts into the `bin/` directory with execution permissions.
  * `make clean`: Removes installed files in `bin/`.
  * `make help`: Lists available targets.
  * Default target (`make`): Runs both `check` and `install`.

---

### Example

```bash
# Check for syntax errors
$ make check
Checking script syntax...
Checking scripts/hello.sh...
All scripts passed syntax check

# Run unit tests (if present in tests/)
$ make test
Running tests/test_hello.sh...
All tests passed

# Install scripts to bin/
$ make install
Scripts installed to bin/

# Clean installed files
$ make clean
```

---

### Known Limitations

* Unit tests are optional — if no test scripts exist in `tests/`, the `make test` step will skip gracefully.
* Installation target defaults to `bin/`; customization requires editing the `BIN_DIR` variable.
* Does not handle nested script directories.

---

### How to Run

1. Place your shell scripts inside the `scripts/` directory.
2. (Optional) Place unit tests inside the `tests/` directory.
3. Run the Makefile commands:

```bash
make check     # Validate script syntax
make test      # Run unit tests
make install   # Install scripts to bin/
make clean     # Remove installed files
make help      # Show available targets
```

---

### What I Verified

* Syntax check fails if a script contains errors.
* Test step executes only if files exist in `tests/`.
* Scripts are copied into `bin/` with execution permissions.

---

### Sources & AI Usage

* The Makefile and README structure were assisted by AI.

---
