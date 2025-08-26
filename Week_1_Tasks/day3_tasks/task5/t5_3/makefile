SCRIPTS := $(wildcard scrips/*.sh)
TESTS := $(wildcard tests/*.sh)
INSTALL_DIR ?= install/

.PHONY : all check test install clean

all : check test

check : 
	@for scripts in $(SCRIPTS); do \
		echo "Checking $$scripts"; \
		bash -n $$scripts || exit 1; \
	done


test : 
	@for tests in $(TESTS); do \
		echo "Testing $$tests"; \
		bash $$tests || exit 1; \
	done
	

install : 
	@mkdir -p $(INSTALL_DIR)
	@for scripts in $(SCRIPTS); do \
		echo "Installing $$scripts to $(INSTALL_DIR)"; \
		install -m 0755 $$scripts $(INSTALL_DIR); \
		 
	done
	echo "Installed all Scripts to $(INSTALL_DIR)";
clean :
	
