SCRIPTS = script1.sh script2.sh
TESTS   = testscript1.sh testscript2.sh
INSTALL_DIR ?= /usr/local/bin

.PHONY: all check test install

all: check test

check:
	@for f in $(SCRIPTS); do \
		bash -n $$f || exit 1; \
		echo "$$f syntax OK"; \
	done

test:
	@for t in $(TESTS); do \
		bash $$t || exit 1; \
	done

install:
	@mkdir -p $(INSTALL_DIR)
	@install -m 755 $(SCRIPTS) $(INSTALL_DIR)
