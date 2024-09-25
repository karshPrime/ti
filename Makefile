
# Compiler and directories
CC = gcc
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin

# Output files
DLL = $(BIN_DIR)/ticolour.dll
TARGET = $(BIN_DIR)/ti.exe

# Object files
DLL_OBJS = $(OBJ_DIR)/ticolour.o
TI_OBJS = $(OBJ_DIR)/actions.o $(OBJ_DIR)/commands.o $(OBJ_DIR)/main.o \
          $(OBJ_DIR)/printbreak.o $(OBJ_DIR)/transform.o

# Flags
CFLAGS = -Wall -O2 -I$(INC_DIR)
LDFLAGS_DLL = -shared -Wl,--out-implib,$(LIB_DIR)/libticolour.a
LDFLAGS_TGT = -L$(LIB_DIR) -lticolour

# Default target
all: $(TARGET)

# Build the DLL
$(DLL): $(DLL_OBJS)
	$(CC) $(LDFLAGS_DLL) -o $@ $(DLL_OBJS)

# Build the executable
$(TARGET): $(TI_OBJS) $(DLL)
	$(CC) -o $@ $(TI_OBJS) $(LDFLAGS_TGT)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create necessary directories
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

# Clean up generated files
clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)/ti.exe $(BIN_DIR)/ticolour.dll

.PHONY: all clean
