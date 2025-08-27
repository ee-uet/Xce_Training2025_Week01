# Shell script project Makefile

# Configuration
SHELL := /bin/bash
SCRIPT_DIR := scripts
TEST_DIR := tests
INSTALL_DIR := /usr/local/bin
DOC_DIR := /usr/local/share/doc/shell-project

# Find all shell scripts
SCRIPTS := $(wildcard $(SCRIPT_DIR)/*.sh)
TEST_SCRIPTS := $(wildcard $(TEST_DIR)/test_*.sh)

# Default target
all: check-syntax

# Check syntax of all shell scripts
check-syntax: $(SCRIPTS)
	@echo "Checking syntax of shell scripts..."
	@for script in $(SCRIPTS); do \
		echo "Checking $$script..."; \
		bash -n "$$script" || exit 1; \
	done
	@echo "All scripts have valid syntax!"

# Run shellcheck if available
shellcheck: $(SCRIPTS)
	@if command -v shellcheck >/dev/null 2>&1; then \
		echo "Running shellcheck..."; \
		shellcheck $(SCRIPTS); \
	else \
		echo "shellcheck not found. Install it for better script analysis."; \
		echo "On Ubuntu/Debian: sudo apt install shellcheck"; \
		echo "On macOS: brew install shellcheck"; \
	fi

# Make scripts executable
make-executable: $(SCRIPTS)
	@echo "Making scripts executable..."
	@chmod +x $(SCRIPTS)

# Run unit tests
test: check-syntax make-executable
	@echo "Running unit tests..."
	@test_failed=0; \
	for test_script in $(TEST_SCRIPTS); do \
		echo "Running $$test_script..."; \
		bash "$$test_script" || test_failed=1; \
		echo ""; \
	done; \
	if [ $$test_failed -eq 0 ]; then \
		echo "All tests passed!"; \
	else \
		echo "Some tests failed!"; \
		exit 1; \
	fi

# Install scripts to system
install: check-syntax make-executable test
	@echo "Installing scripts to $(INSTALL_DIR)..."
	@mkdir -p $(INSTALL_DIR)
	@for script in $(SCRIPTS); do \
		script_name=$$(basename "$$script" .sh); \
		echo "Installing $$script as $$script_name..."; \
		cp "$$script" "$(INSTALL_DIR)/$$script_name"; \
		chmod +x "$(INSTALL_DIR)/$$script_name"; \
	done
	@echo "Installation complete!"

# Uninstall scripts from system
uninstall:
	@echo "Uninstalling scripts from $(INSTALL_DIR)..."
	@for script in $(SCRIPTS); do \
		script_name=$$(basename "$$script" .sh); \
		if [ -f "$(INSTALL_DIR)/$$script_name" ]; then \
			echo "Removing $$script_name..."; \
			rm -f "$(INSTALL_DIR)/$$script_name"; \
		fi; \
	done
	@echo "Uninstallation complete!"

# Create a distribution package
package: check-syntax test
	@echo "Creating distribution package..."
	@mkdir -p dist/shell-project-1.0/{scripts,tests,doc}
	@cp $(SCRIPTS) dist/shell-project-1.0/scripts/
	@cp $(TEST_SCRIPTS) dist/shell-project-1.0/tests/
	@cp Makefile dist/shell-project-1.0/
	@echo "Shell Script Project v1.0" > dist/shell-project-1.0/doc/README.txt
	@echo "Install with: make install" >> dist/shell-project-1.0/doc/README.txt
	@cd dist && tar czf shell-project-1.0.tar.gz shell-project-1.0/
	@echo "Package created: dist/shell-project-1.0.tar.gz"

# Show script information
info:
	@echo "=== Shell Script Project Information ==="
	@echo "Scripts found:"
	@for script in $(SCRIPTS); do \
		echo "  - $$script"; \
		head -2 "$$script" | tail -1; \
	done
	@echo ""
	@echo "Test scripts found:"
	@for test in $(TEST_SCRIPTS); do \
		echo "  - $$test"; \
	done
	@echo ""
	@echo "Install directory: $(INSTALL_DIR)"

# Clean up temporary files
clean:
	@echo "Cleaning up..."
	@rm -rf dist/
	@rm -f /tmp/test_file_*
	@echo "Clean complete!"

# Development target - run syntax check and tests
dev: check-syntax shellcheck test
	@echo "Development checks complete!"

# Declare phony targets
.PHONY: all check-syntax shellcheck make-executable test install uninstall package info clean dev