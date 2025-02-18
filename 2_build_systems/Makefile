# Compiler
CC = g++

# Project name
PROJECT = build_systems

# Dynamic project source directory
PROJECT_SOURCE_DIR := $(shell dirname $(shell pwd))
CPPFLAGS += -DPROJECT_SOURCE_DIR=\"$(PROJECT_SOURCE_DIR)\"

# Default source file (if not specified)
SRC ?= 2_build_systems.cpp  

# Compiler flags
CFLAGS = -std=c++11 $(shell pkg-config --cflags opencv4) $(shell pkg-config --cflags sdl2)

# Libraries
LIBS = $(shell pkg-config --libs opencv4) $(shell pkg-config --libs sdl2)

# Build
.PHONY: build
build:
	@echo "Building $(SRC)..."
	@$(CC) $(CPPFLAGS) $(CFLAGS) $(SRC) -o $(PROJECT) $(LIBS)
# Clean 
.PHONY: clean
clean:
	@echo "Cleaning..."
	@rm -rf $(PROJECT)
