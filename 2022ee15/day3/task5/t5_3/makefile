SCRIPTS := $(wildcard scrips/*.sh)
TESTS := $(wildcard tests/*.sh)
INSTALL_DIR ?= install/

.PHONY : all check test install clean

all : check test
# syntax check: use bash -n to check without running
check : 
	@for scripts in $(SCRIPTS); do \
		echo "Checking $$scripts"; \
		bash -n $$scripts || exit 1; \
	done

# run unit tests (test scripts should return non-zero on failure)
test : 
	@for tests in $(TESTS); do \
		echo "Testing $$tests"; \
		bash $$tests || exit 1; \
	done
	
# install scripts to INSTALL_DIR with executable permission
install : 
	@mkdir -p $(INSTALL_DIR)
	@for scripts in $(SCRIPTS); do \
		echo "Installing $$scripts to $(INSTALL_DIR)"; \
		install -m 0755 $$scripts $(INSTALL_DIR); \
		 
	done
	echo "Installed all Scripts to $(INSTALL_DIR)";
clean :
	
