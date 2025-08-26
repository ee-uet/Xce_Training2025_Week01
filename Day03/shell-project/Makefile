
SHELL = /bin/bash
SCRIPTS_DIR = scripts
TESTS_DIR = tests
BIN_DIR = bin

SCRIPTS = $(wildcard $(SCRIPTS_DIR)/*.sh)
SCRIPT_NAMES = $(notdir $(SCRIPTS))
INSTALL_TARGETS = $(addprefix $(BIN_DIR)/, $(SCRIPT_NAMES))


all: check install


check: $(SCRIPTS)
	@echo "Checking script syntax..."
	@for script in $^; do \
		echo "Checking $$script..."; \
		bash -n "$$script" || exit 1; \
	done
	@echo "All scripts passed syntax check"

test:
	@echo "Running unit tests..."
	@if [ -d "$(TESTS_DIR)" ] && [ -n "$(wildcard $(TESTS_DIR)/*.sh)" ]; then \
		for test_file in $(TESTS_DIR)/*.sh; do \
			echo "Running $$test_file..."; \
			bash "$$test_file" || exit 1; \
		done; \
		echo "All tests passed"; \
	else \
		echo "No tests found in $(TESTS_DIR)"; \
	fi


install: $(INSTALL_TARGETS)
	@echo "Scripts installed to $(BIN_DIR)/"


$(BIN_DIR)/%: $(SCRIPTS_DIR)/%
	@mkdir -p $(BIN_DIR)
	cp "$<" "$@"
	chmod +x "$@"

clean:
	rm -rf $(BIN_DIR)

help:
	@echo "Available targets:"
	@echo "  make check     - Validate script syntax"
	@echo "  make test      - Run unit tests"
	@echo "  make install   - Install to local bin directory"
	@echo "  make           - Run check + install (default)"
	@echo "  make clean     - Remove build artifacts"

.PHONY: all check test install clean help