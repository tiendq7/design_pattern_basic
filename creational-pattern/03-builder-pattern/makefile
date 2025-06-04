CC := gcc
CFLAGS := -Wall -Wextra -std=c99 -Iinc
OBJ_DIR := build
BIN := uart_app

SRCS := src/uart_config.c
OBJS := $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))
MAIN_OBJ := $(OBJ_DIR)/main.o

all: $(BIN)

$(BIN): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_OBJ): main.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN)

run: $(BIN)
	./$(BIN)
