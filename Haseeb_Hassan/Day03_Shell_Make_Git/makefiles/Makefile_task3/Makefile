

SCRIPTS := greet.sh fruits.sh
INSTALL_DIR := /usr/local/bin

.PHONY: all check test install clean


all: check test


check:
	@echo "Checking scripts for syntax errors..."
	@for script in $(SCRIPTS); do \
		echo "Checking $$script..."; \
		bash -n $$script || exit 1; \
	done
	@echo "All scripts passed syntax check."


test:
	@echo "Running tests..."
	@if [ -d tests ]; then \
		for t in tests/*.sh; do \
			echo "Running $$t..."; \
			bash $$t || exit 1; \
		done \
	else \
		echo "No tests found."; \
	fi

install: check
	@echo "Installing scripts to $(INSTALL_DIR)..."
	@mkdir -p $(INSTALL_DIR)
	@for script in $(SCRIPTS); do \
		install -m 755 $$script $(INSTALL_DIR); \
		echo "Installed $$script to $(INSTALL_DIR)"; \
	done


clean:
	@echo "Nothing to clean."
