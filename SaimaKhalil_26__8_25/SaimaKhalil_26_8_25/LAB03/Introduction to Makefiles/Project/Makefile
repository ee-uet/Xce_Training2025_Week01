# Scripts
HELLO = scripts/hello.sh
BYE = scripts/bye.sh

# Destination folder on Windows mounted in WSL
INSTALL_DIR = "/mnt/c/Users/Hp/Desktop/XCELERIUM/LAB03/Introduction\ to\ Makefiles/Project/copy_scripts"

# Default: check syntax
all: check
# bash -n means sirf syntax validate kare, run na kare
check:
	@echo "Checking scripts..."
	@bash -n $(HELLO) 
	@bash -n $(BYE)
	@echo "All scripts OK"

# Run scripts
run: check
	@echo "Running scripts..."
	@bash $(HELLO)
	@bash $(BYE)

# Install scripts to mounted Windows folder
install: check
	@echo "Installing scripts to $(INSTALL_DIR)..."
	@mkdir -p "$(INSTALL_DIR)"
	@cp $(HELLO) "$(INSTALL_DIR)/"
	@cp $(BYE) "$(INSTALL_DIR)/"
	@chmod +x "$(INSTALL_DIR)/hello.sh"
	@chmod +x "$(INSTALL_DIR)/bye.sh"
	@echo "Installed!"

# Clean
clean:
	@echo "Nothing to clean"
