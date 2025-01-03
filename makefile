# Makefile

# Compiler settings
CC = gcc
CXX = g++
PYTHON = python3
WIN_CC = x86_64-w64-mingw32-gcc

# Common settings
CFLAGS = -IInclude -O2 -Wall -std=c99
CXXFLAGS = -IInclude -O2 -Wall -std=c++17

# Raylib paths for Linux
RAYLIB_INCLUDE_LINUX = /usr/local/include/raylib
RAYLIB_LIB_LINUX = /usr/local/lib

# Linking settings
LDFLAGS_LINUX = -I$(RAYLIB_INCLUDE_LINUX) -L$(RAYLIB_LIB_LINUX) -lraylib -lm -lpthread -ldl
LDFLAGS_WINDOWS = -I/home/archkubi/tmp/raylib/src -L/home/archkubi/tmp/raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm -static -s -Wl,-subsystem,windows

# Directories
SRC_DIR = .
OBJ_DIR = Object
BUILD_DIR = Build

# Targets
CFile_LinuxBuild: $(SRC_DIR)/main.c
	$(CC) -o $(BUILD_DIR)/debug_Linux $(SRC_DIR)/main.c $(CFLAGS) $(LDFLAGS_LINUX)

CFile_WindowBuild: $(SRC_DIR)/main.c
	$(WIN_CC) -o $(BUILD_DIR)/debug_Windows.exe $(SRC_DIR)/main.c $(CFLAGS) $(LDFLAGS_WINDOWS)

CPPFile_LinuxBuild: $(SRC_DIR)/main.cpp
	$(CXX) -o $(BUILD_DIR)/debug_LinuxCpp $(SRC_DIR)/main.cpp $(CXXFLAGS) $(LDFLAGS_LINUX)

# Clean target
clean:
	rm -f $(BUILD_DIR)/debug_Linux $(BUILD_DIR)/debug_Windows.exe $(BUILD_DIR)/debug_LinuxCpp
	rm -f $(OBJ_DIR)*.o

.PHONY: clean
