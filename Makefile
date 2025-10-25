# Makefile for Professional Calculator
# Author: Jaden Mardini

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror -O2 -g
LDFLAGS = 
LDLIBS = -lm

# Directories
SRC_DIR = src
BIN_DIR = bin
DOCS_DIR = docs

# Source files
CALCULATOR_SRC = $(SRC_DIR)/calculator.c

# Executables
CALCULATOR_EXEC = $(BIN_DIR)/calculator

.PHONY: all clean directories calculator test help

# Default target
all: directories $(CALCULATOR_EXEC)

# Create directories
directories:
	@mkdir -p $(BIN_DIR) $(DOCS_DIR)

# Calculator executable
$(CALCULATOR_EXEC): $(CALCULATOR_SRC)
	@echo "Building calculator..."
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< $(LDLIBS)

# Individual target
calculator: directories $(CALCULATOR_EXEC)

# Test target
test: all
	@echo "Calculator built successfully"
	@echo "Run './bin/calculator' to start the application"

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -rf $(BIN_DIR)
	@echo "Clean complete"

# Help target
help:
	@echo "Available targets:"
	@echo "  all        - Build calculator (default)"
	@echo "  calculator - Build calculator"
	@echo "  test       - Build and verify"
	@echo "  clean      - Remove build artifacts"
	@echo "  help       - Show this help message"
