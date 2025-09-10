# Exercise 5.3: Makefile for Shell Script Project
# Fixed: Changed spaces to TABS and corrected syntax errors

SCRIPTS := $(wildcard scripts/*.sh)	# target all shell scripts in scripts/ directory
TESTS := $(wildcard tests/*.sh)		# target all test scripts in tests/ directory
INSTALL_DIR ?= install/

.PHONY: all check test install clean

all: check test

# Check syntax of all scripts
check: 
	@for script in $(SCRIPTS); do \
		echo "Checking $$script"; \
		bash -n $$script || exit 1; \
	done

# Run all test scripts
test: 
	@for test in $(TESTS); do \
		echo "Testing $$test"; \
		bash $$test || exit 1; \
	done

# Install scripts to INSTALL_DIR
install: 
	@mkdir -p $(INSTALL_DIR)
	@for script in $(SCRIPTS); do \
		echo "Installing $$script to $(INSTALL_DIR)"; \
		install -m 0755 $$script $(INSTALL_DIR); \		#-m 0755 sets executable permissions
	done
	@echo "Installed all scripts to $(INSTALL_DIR)"

clean:
	@echo "Nothing to clean for script project"