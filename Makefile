
CC = gcc
CFLAGS = -Wall -O2 -Ilib
LDFLAGS = -Llib -lm

OBJ_DIR = obj
SRC_DIR = src
BIN_DIR = bin
LIB_DIR = lib

OBJS = $(OBJ_DIR)/actions.o $(OBJ_DIR)/commands.o $(OBJ_DIR)/main.o \
       $(OBJ_DIR)/printbreak.o $(OBJ_DIR)/transform.o
DLL_OBJS = $(OBJ_DIR)/ticolour.o

TARGET = $(BIN_DIR)/ti.exe
DLL = $(LIB_DIR)/ticolour.dll

all: $(TARGET)

$(TARGET): $(OBJS) $(DLL)
	$(CC) -o $@ $(OBJS) $(LDFLAGS) -lticolour

$(DLL): $(DLL_OBJS)
	$(CC) -shared -o $(DLL) $(DLL_OBJS) -Wl,--out-implib,$(LIB_DIR)/libticolour.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/* $(LIB_DIR)/*.dll $(LIB_DIR)/*.a

