# TARGET EXECUTABLE
TARGET = client

# LIBRARIES
LIBRARIES = -lcore

# INPUT DIRECTORIES
SRC_DIR = src
INCLUDE_DIR = -Iinclude -I../core/include
LIBRARY_DIR = -L../build/bin/core -L../libs

# OUTPUT DIRECTORIES
BIN_DIR = ../build/bin/$(TARGET)
OBJ_DIR = ../build/obj/$(TARGET)

# FILES TO INCLUDE IN TARGETS
FILES := $(shell find $(SRC_DIR) -name "*.c")

# ALL SUBDIRECTORIES IN SOURCE FOLDER
FOLDERS := $(shell find $(SRC_DIR) -type d)

# BUILD MODE
BUILD = DEBUG

# C COMPILER
CC = clang

# COMPILER FLAGS
CFLAGS = -ansi $(INCLUDE_DIR)

# DEBUG FLAGS
DEBUG_FLAGS = -Wall -Werror -pedantic -g

ifeq ($(BUILD), DEBUG)
    CFLAGS += $(DEBUG_FLAGS)
endif

# LINKER FLAGS
CFLAGS_L = -fsanitize=address,undefined

# MAIN TARGET
$(TARGET): $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(FILES:.c=.o))
	@echo "    Building $(TARGET)"
	@$(CC) $(CFLAGS_L) $(LIBRARY_DIR) $^ $(LIBRARIES) -o $(BIN_DIR)/$(TARGET)

# CREATE OBJECT FILES
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | init
	@echo "    Building object file $(patsubst ../build/obj/%,%, $@) in ../build/bin"
	@$(CC) $(CFLAGS) -c $^ -o $@

# CREATE DIRECTORIES IF NOT ALREADY CREATED
init:
	@echo "    Creating directories for $(TARGET)"
	@mkdir -p ../build/bin $(BIN_DIR) ../build/obj $(OBJ_DIR) $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(FOLDERS))

.PHONY: clean

# REMOVE ALL FILES IN BUILD DIRECTORY
clean:
	@echo "    Cleaning $(TARGET)"
	@rm -rf $(BIN_DIR)/* $(OBJ_DIR)/*
