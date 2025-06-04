# Project: Singleton SensorManager
# Makefile (Professional Layout)

CC := gcc
CFLAGS := -Wall -Wextra -std=c99 -Isrc -Iinc

SRC_DIR := src
INC_DIR := inc
OBJ_DIR := build
BIN := sensor_app

# Main file (outside src)
MAIN := main.c

# Source files in src (excluding main.c)
SRCS := $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
MAIN_OBJ := $(OBJ_DIR)/main.o

# Default target
all: $(BIN)

# Link all objects to build the binary
$(BIN): $(OBJS) $(MAIN_OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/main.o: main.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean run

run: $(BIN)
	./$(BIN)

clean:
	rm -rf $(OBJ_DIR) $(BIN)
