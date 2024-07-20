# Compiler
CC=gcc

# Compiler flags
CFLAGS=-Wall -g -pedantic -std=c11

# Linker flags
LDFLAGS=-lm

# Directories
SRC_DIR=src
BUILD_DIR=build

# Source files
SRC=$(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ=$(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Executable
EXEC=$(BUILD_DIR)/main

# Default target
all: build $(EXEC)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Link object files into the final executable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Run the executable
run: $(EXEC)
	./$(EXEC)

# Clean object files
clean:
	rm -f $(BUILD_DIR)/*.o

# Clean all generated files and build directory
cleanall: clean
	rm -rf $(BUILD_DIR)

.PHONY: all build run clean cleanall