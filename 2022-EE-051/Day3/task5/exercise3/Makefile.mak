# Variables
SCRIPTS := $(wildcard scripts/*.sh)
TESTS := $(wildcard tests/*.sh)
INSTALL_DIR ?= /usr/local/bin   # Default install directory, can be overridden
SHELL := /bin/bash

# Default target
all: check test

# 1. Check syntax of shell scripts
check:
	@echo "Checking syntax of shell scripts..."
	@for script in $(SCRIPTS); do \
		echo "Checking $$script..."; \
		bash -n $$script || { echo "Syntax error in $$script"; exit 1; }; \
	done
	@echo "All scripts passed syntax check."
# 2. Run unit tests if available
test:
	@if [ -n "$(TESTS)" ]; then \
		echo "Running tests..."; \
		for test in $(TESTS); do \
			bash $$test || exit 1; \
		done; \
		echo "All tests passed."; \
	else \
		echo "No tests found."; \
	fi

# 3. Install scripts to specified directory
install: all
	@echo "Installing scripts to $(INSTALL_DIR)..."
	@mkdir -p $(INSTALL_DIR)
	@for script in $(SCRIPTS); do \
                dset=$(INSTALL_DIR)/$$(basename $$script); \
                echo "Copying $$script to dset";\
		cp $$script $$dset; \
		chmod +x $$dset; \
	done
	@echo "Installation complete."
# Clean target (optional)
clean:
	@echo "Nothing to clean for shell scripts."

.PHONY: all check test install clean

