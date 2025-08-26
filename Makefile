SCRIPTS = my_script1.sh my_script2.sh
TESTS = $(wildcard tests/test_*.sh)
INSTALL_DIR = /home/naqi-ul-hassan/Desktop/Scripting_practice/Makefile_practice/Part3/INSTALL_DIR

all: check

check:
	@echo "Checking shell scripts for syntax errors..."
	@for script in $(SCRIPTS); do \
		bash -n $$script || exit 1; \
	done
	@echo "All scripts passed syntax check."

test: check
	@if [ -n "$(TESTS)" ]; then \
		echo "Running unit tests..."; \
		for t in $(TESTS); do \
			echo "Running $$t..."; \
			bash $$t || exit 1; \
		done; \
	else \
		echo "No tests found."; \
	fi
	@echo "All tests passed."

install: check
	@echo "Installing scripts to $(INSTALL_DIR)..."
	@mkdir -p $(INSTALL_DIR)
	@for script in $(SCRIPTS); do \
		install -m 755 $$script $(INSTALL_DIR); \
	done
	@echo "Installation complete."

clean:
	rm -f *~ tests/*~

