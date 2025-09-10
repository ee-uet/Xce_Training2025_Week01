## Task 5.3 — Makefile for Bash Scripts

This project demonstrates how to manage, check, run, and install **Bash scripts** using a **Makefile**.  
The scripts are:

- `scripts/hello.sh`
- `scripts/bye.sh`

The Makefile automates checking their syntax, running them, installing them , and then cleaning.

---

### Makefile Overview

###  Variables
```makefile
HELLO = scripts/hello.sh
BYE = scripts/bye.sh

INSTALL_DIR = "/mnt/c/Users/Hp/Desktop/XCELERIUM/LAB03/Introduction\ to\ Makefiles/Project/copy_scripts"
HELLO, BYE :Paths of the Bash scripts.

INSTALL_DIR :Destination folder in Windows (in WSL).
```

Default Target
```makefile
all: check
```
By default, running make will check script syntax.

**Check Script Syntax**
```makefile
check:
	@echo "Checking scripts..."
	@bash -n $(HELLO)
	@bash -n $(BYE)
	@echo "All scripts OK"
```

Uses bash -n to validate syntax (does not execute the scripts).

**Run Scripts**
```makefile
run: check
	@echo "Running scripts..."
	@bash $(HELLO)
	@bash $(BYE)
```
Executes the scripts sequentially after syntax check passes.

**Install Scripts**
```makefile
install: check
	@echo "Installing scripts to $(INSTALL_DIR)..."
	@mkdir -p "$(INSTALL_DIR)"
	@cp $(HELLO) "$(INSTALL_DIR)/"
	@cp $(BYE) "$(INSTALL_DIR)/"
	@chmod +x "$(INSTALL_DIR)/hello.sh"
	@chmod +x "$(INSTALL_DIR)/bye.sh"
	@echo "Installed!"
```
Ensures destination directory exists.
Copies scripts into Windows folder.
Makes them executable with chmod +x.

**Clean Target**
```makefile
clean:
	@echo "Nothing to clean"
```
nothing to clean.

---

### Run
Check syntax only
```bash
make
```
or
```bash
make check
```
Run scripts
```bash
make run
```
Install scripts into Windows folder
```bash
make install
```
Clean
```bash
make clean
```

---