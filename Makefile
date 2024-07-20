CC=gcc
CFLAGS=-Wall -g -pedantic -std=c11
LDFLAGS=-lm

SRC_DIR=src
BUILD_DIR=build

OBJ=$(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

MAIN=$(BUILD_DIR)/main.o

build: mkdir -p $(BUILD_DIR)
	$(OBJ)

run:
	./$(MAIN)

clean:
	rm -f $(BUILD_DIR)/*.o

cleanall: clean
	rm -rf $(BUILD_DIR)