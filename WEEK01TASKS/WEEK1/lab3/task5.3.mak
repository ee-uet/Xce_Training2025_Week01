files = $(wildcard *.sh)
LOCATION ?= $(HOME)/bin

.PHONY: all syntax_error test clean install uninstall

all: syntax_error

syntax_error:
	@for file in $(files); do \
		bash -n $$file || exit 1; \
		echo "$$file: Syntax OK"; \
	done
	@echo "All scripts passed syntax check!"

test:
	@echo "Running unit tests..."
	@./fruits.sh

clean:
	@echo "Nothing to clean"

install:
	@mkdir -p $(LOCATION); \
	for file in $(files); do \
		cp $$file $(LOCATION); \
		chmod +x $(LOCATION)/$$file; \
		echo "Installed $$file"; \
	done

uninstall:
	@for file in $(files); do \
		rm -f $(LOCATION)/$$file; \
		echo "Removed $$file from $(LOCATION)"; \
	done
