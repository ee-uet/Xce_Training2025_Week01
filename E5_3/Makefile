
shell_files = $(wildcard *.sh)
install_dir = /home/hafiz/Documents/X_training/Bash/E5_3/instal
SHELL_CHECK = shellcheck

all: check

check:
	@for script in $(shell_files); do \
		if [ -f $$script ]; then \
			echo "Checking $$script file syntax "; \
			$(SHELL_CHECK) $$script || exit 1; \
		else \
			echo "This $$script file does not exit"; \
		fi; \
	done 

	@echo "Successfully checked syntax of all files"
	@echo ""
test:
	@if [ -d Tests ]; then \
		echo "Run Tests"; \
		for testt in Tests/*.sh; do \
			echo "Run this test $$testt"; \
			bash $$testt || exit 1 ;\
		done; \
		echo "Run all tests successfully"; \
	else \
		echo "Directory does not exist"; \
	fi; \

	@echo ""

install:
	@for script in $(shell_files); do \
		if [ -f $$script ]; then \
			echo "Installing $$script to this path$(install_dir)"; \
			install -m 755 $$script $(install_dir); \
		else \
			echo "File not exist"; \
		fi; \
	done 


