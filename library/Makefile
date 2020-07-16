# TARGET EXECUTABLE
TARGET = library

# C COMPILER
CC = clang

# FLAGS
CFLAGS = -Iinclude

# BUILD MODE
BUILD = DEBUG

ifeq ($(BUILD), DEBUG)	
    CFLAGS = -ansi -Wall -Werror -pedantic -g
endif

# ALL C FILES IN SOURCE FOLDER
FILES := $(shell find src -name "*.c")

# ALL SUBDIRECTORIES IN SOURCE FOLDER
FOLDERS := $(shell find src -type d)

# MAIN TARGET
$(TARGET): $(patsubst src/%, build/obj/%, $(FILES:.c=.o)) | remake
	@echo "    Rebuilding $(TARGET)"
	@ar r build/bin/lib$(TARGET).a $^

# DELETE EXISTING ARCHIVE
remake:
	@rm -f build/bin/$(TARGET)

# CREATE OBJECT FILES
build/obj/%.o: src/%.c | init
	@echo "    Building object file $@ for $(TARGET)"
	@$(CC) $(CFLAGS) -c $^ -o $@

# CREATE DIRECTORIES IF NOT ALREADY CREATED
init:
	@echo "    Creating directories for $(TARGET)"
	@mkdir -p build/bin build/obj $(patsubst src/%, build/obj/%, $(FOLDERS))

.PHONY: clean

# REMOVE ALL FILES IN BUILD DIRECTORY
clean:
	@echo "    Cleaning $(TARGET)"
	@rm -rf build/bin/* build/obj/*
