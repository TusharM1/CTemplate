# TARGET EXECUTABLE
TARGET = server

# C COMPILER
CC = clang

# FLAGS
CFLAGS = -Iinclude -I../library/include

# COMPILER FLAGS
CFLAGS_C = -ansi -Wall -Werror -pedantic -g

# BUILD MODE
BUILD = DEBUG

ifeq ($(BUILD), DEBUG)
    CFLAGS += $(CFLAGS_C)
endif

# LINKER FLAGS
CFLAGS_L = -fsanitize=address,undefined

# LIBRARIES
LIBRARY_FOLDERS = -L../library/build/bin
LIBRARIES = -llibrary

# FILES TO INCLUDE IN TARGETS
FILES := $(shell find src -name "*.c")

# ALL SUBDIRECTORIES IN SOURCE FOLDER
FOLDERS := $(shell find src -type d)

# MAIN TARGET
$(TARGET): $(patsubst src/%, build/obj/%, $(FILES:.c=.o))
	@echo "    Building $(TARGET)"
	@$(CC) $(CFLAGS_L) $(LIBRARY_FOLDERS) $^ $(LIBRARIES) -o build/bin/$(TARGET) 

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