# Project: Library Management System
# Makefile (Professional Layout)

CC := gcc
CFLAGS := -Wall -Wextra -std=c99 -Iinc
SRC_DIR := src
INC_DIR := inc
OBJ_DIR := build
BIN := library

MAIN := main.c
SRCS := $(filter-out $(MAIN), $(wildcard $(SRC_DIR)/*.c))
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
MAIN_OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(MAIN))

$(BIN): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean run

run: $(BIN)
	./$(BIN)

clean:
	rm -rf $(OBJ_DIR) $(BIN)
