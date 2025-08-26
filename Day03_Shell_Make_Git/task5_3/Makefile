
SCRIPTS = task1_.sh task1_3.sh
TEST_FILES = test_task1_1.sh test_task1_3.sh

PREFIX = /usr/local/bin

.PHONY: all check test install clean


all: check test

check:
	@echo "Checking syntax..."
	@for s in $(SCRIPTS); do \
		bash -n $$s || exit 1; \
		echo "$$s passed syntax ckeck..."; \
	done
	@echo "All scripts passed syntax check."

test:
	@echo "Running tests..."
	@for t in $(TEST_FILES); do \
		bash $$t || exit 1; \
	done
	@echo "All tests passed."

install:
	@echo "Installing scripts to $(PREFIX)..."
	@for s in $(SCRIPTS); do \
		install -m 755 $$s $(PREFIX); \
	done
	@echo "Installation complete."

clean:
	@echo "Nothing to clean for shell scripts."
