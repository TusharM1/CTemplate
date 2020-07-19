# TARGET EXECUTABLE
TARGET = core

# LIBRARIES
LIBRARIES = -lcore

# INPUT DIRECTORIES
SRC_DIR = src
INCLUDE_DIR = -Iinclude
LIBRARY_DIR = -L../libs

# OUTPUT DIRECTORIES
BIN_DIR = ../build/bin/$(TARGET)
OBJ_DIR = ../build/obj/$(TARGET)

# ALL C FILES IN SOURCE FOLDER
FILES := $(shell find src -name "*.c")

# ALL SUBDIRECTORIES IN SOURCE FOLDER
FOLDERS := $(shell find src -type d)

# BUILD MODE
BUILD = DEBUG

# C COMPILER
CC = clang

# FLAGS
CFLAGS = -ansi $(INCLUDE_DIR)

ifeq ($(BUILD), DEBUG)	
    CFLAGS += -Wall -Werror -pedantic -g
endif

# MAIN TARGET
$(TARGET): $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(FILES:.c=.o)) | remake
	@echo "    Rebuilding $(TARGET)"
	@ar r $(BIN_DIR)/lib$(TARGET).a $^

# DELETE EXISTING ARCHIVE
remake:
	@rm -f $(BIN_DIR)/lib$(TARGET).a

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
