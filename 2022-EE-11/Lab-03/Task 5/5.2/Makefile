# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
DEBUGFLAGS = -g -DDEBUG
RELEASEFLAGS = -O2 -DNDEBUG

# Directories
SRCDIR = .
OBJDIR = obj
DEPDIR = dep

# Target executable
TARGET = myprogram
DEBUG_TARGET = myprogram_debug

# Automatically find all .c files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEBUG_OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.debug.o)
DEPENDENCIES = $(SOURCES:$(SRCDIR)/%.c=$(DEPDIR)/%.d)

# Create directories if they don't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(DEPDIR):
	mkdir -p $(DEPDIR)

# Default target
all: $(TARGET)

# Debug target
debug: $(DEBUG_TARGET)

# Link the release executable
$(TARGET): $(OBJDIR) $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Link the debug executable
$(DEBUG_TARGET): $(OBJDIR) $(DEBUG_OBJECTS)
	$(CC) $(DEBUG_OBJECTS) -o $(DEBUG_TARGET)

# Compile source files for release
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) $(RELEASEFLAGS) -MMD -MP -MF $(DEPDIR)/$*.d -c $< -o $@

# Compile source files for debug
$(OBJDIR)/%.debug.o: $(SRCDIR)/%.c | $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -MMD -MP -MF $(DEPDIR)/$*.debug.d -c $< -o $@

# Include dependency files
-include $(DEPENDENCIES)
-include $(DEPENDENCIES:%.d=%.debug.d)

# Clean up build files
clean:
	rm -rf $(OBJDIR) $(DEPDIR) $(TARGET) $(DEBUG_TARGET)

# Clean only object files
clean-obj:
	rm -rf $(OBJDIR)

# Show variables (useful for debugging Makefile)
show:
	@echo "SOURCES: $(SOURCES)"
	@echo "OBJECTS: $(OBJECTS)"
	@echo "DEBUG_OBJECTS: $(DEBUG_OBJECTS)"
	@echo "DEPENDENCIES: $(DEPENDENCIES)"

# Install target (optional)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Uninstall target (optional)
uninstall:
	rm -f /usr/local/bin/$(TARGET)

# Declare phony targets
.PHONY: all debug clean clean-obj show install uninstall