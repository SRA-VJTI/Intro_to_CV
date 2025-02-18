# Specifying which compiler to use
CC = g++							

# Defining the name of the object that will be created after using make
PROJECT = morphology		

# Here Include specifies which directories can be added in the include path of the main.cpp
CFLAGS = -std=c++11 $(shell pkg-config --cflags opencv4) -Iinclude/		
# What libraries to be imported here it is opencv 
LIBS = $(shell pkg-config --libs opencv4) 

# Source file for morphology operations
link = src/morphology.cpp

# Similar to how we used to link and make object files in the terminal
# The command make build SRC=<FILENAME> should build the executable in the subfolder
.PHONY: build
ifeq ($(SRC), $(link), )
build:
	$(error "SRC is not set")
else
build:
	@echo "Building..."
	@$(CC) $(SRC) $(link) -o $(PROJECT) $(CFLAGS) $(LIBS)
endif	

# If folder is not set, clean all build files in all subfolders
.PHONY: clean
clean:
	@echo "Cleaning..."
	@rm -rf $(PROJECT)