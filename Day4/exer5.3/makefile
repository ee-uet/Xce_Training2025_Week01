# Makefile for Shell Script Project

all: check

check: script1.sh script2.sh
	bash -n script1.sh
	bash -n script2.sh
	@echo "Syntax check completed."

test: test_script1.sh test_script2.sh
	bash test_script1.sh
	bash test_script2.sh
	@echo "Tests completed."

install: script1.sh script2.sh
	cp script1.sh /home/aleeza/copied_5.3
	cp script2.sh /home/aleeza/copied_5.3
	chmod +x /home/aleeza/copied_5.3/script1.sh
	chmod +x /home/aleeza/copied_5.3/script2.sh
	@echo "Scripts installed to /home/aleeza/copied_5.3"

clean:
	@echo "Nothing to clean for shell scripts."

