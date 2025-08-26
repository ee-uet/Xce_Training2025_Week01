# Define variables
SHELL_SCRIPTS = script1.sh script2.sh
TEST_SCRIPTS = test_script1.sh
INSTALL_DIR = /usr/local/bin

all: lint test

lint:
	@echo "--- Checking syntax for all shell scripts ---"
	@for script in $(SHELL_SCRIPTS); do \
		echo "Checking $$script..."; \
		bash -n $$script; \
	done

test:
	@echo "--- Running unit tests ---"
	@for test_script in $(TEST_SCRIPTS); do \
		echo "Running $$test_script..."; \
		./$$test_script; \
	done


install:
	@echo "--- Installing shell scripts to $(INSTALL_DIR) ---"
	@if [ ! -d "$(INSTALL_DIR)" ]; then \
		echo "Creating directory $(INSTALL_DIR)"; \
		sudo mkdir -p $(INSTALL_DIR); \
	fi
	@for script in $(SHELL_SCRIPTS); do \
		echo "Installing $$script..."; \
		sudo cp $$script $(INSTALL_DIR)/$$script; \
		sudo chmod +x $(INSTALL_DIR)/$$script; \
	done

clean:
	@echo "--- Cleaning up ---"
	@rm -f test_results.log

.PHONY: all lint test install clean
