# Makefile for Shell Script Project

all: check

# Target to check syntax of scripts
check: script1.sh script2.sh
	bash -n script1.sh
	bash -n script2.sh
	@echo "Syntax check completed."

# Target to run the test scripts
test: test_script1.sh test_script2.sh
	bash test_script1.sh
	bash test_script2.sh
	@echo "Tests completed."

# Target to install scripts to a specific directory
install: script1.sh script2.sh
	cp script1.sh /home/aleeza/copied_5.3
	cp script2.sh /home/aleeza/copied_5.3
	@echo "Scripts installed to /home/aleeza/copied_5.3"


# Target to clean files (nothing to clean for shell scripts here)
clean:
	@echo "Nothing to clean for shell scripts."

