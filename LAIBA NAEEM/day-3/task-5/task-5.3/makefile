SCRIPTS = $(wildcard script*.sh)    
TESTS   = $(wildcard test_*.sh)      
INSTALL_DIR = /mnt/c/Users/123/Desktop/xcelerium

all: syntax test install

syntax:
	@echo "Checking syntax"
	@for file in $(SCRIPTS); do \
		bash -n $$file || exit 1; \
	done
	@echo "All scripts passed syntax check!"

test:
	@echo "Running unit tests"
	@for t in $(TESTS); do \
		bash $$t || exit 1; \
	done
	@echo "All tests passed!"

install: syntax test
	@echo "Installing scripts to $(INSTALL_DIR)..."
	install -m 755 $(SCRIPTS) $(INSTALL_DIR)
	@echo "Scripts installed successfully!"

clean:
	rm -f *.o *.d
