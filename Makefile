INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./build
LIB_DIR = ./lib
BIN_DIR = ./bin

CC      = g++
CFLAGS  = -Wall -pedantic -std=c++11 -ansi -I. -I$(INC_DIR) -g
ARCHIVE = ar

linux: airtonneto.a airtonneto.so prog_estatico prog_dinamico

windows: airtonneto.lib airtonneto.dll prog_estatico.exe prog_dinamico.exe

#LINUX
airtonneto.a: $(SRC_DIR)/lista.cpp $(INC_DIR)/biblio.h $(INC_DIR)/pilha.h $(INC_DIR)/lista.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/lista.cpp -o $(OBJ_DIR)/lista.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/lista.o
	@echo "+++ [Biblioteca estatica criada em $(LIB_DIR)/$@] +++"

airtonneto.so: $(SRC_DIR)/lista.cpp $(INC_DIR)/biblio.h $(INC_DIR)/pilha.h $(INC_DIR)/lista.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/lista.cpp -o $(OBJ_DIR)/lista.o
	$(CC) -shared -fPIC -o $(LIB_DIR)/$@ $(OBJ_DIR)/lista.o
	@echo "+++ [Biblioteca dinamica criada em $(LIB_DIR)/$@] +++"

prog_estatico:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/airtonneto.a -o $(BIN_DIR)/$@

prog_dinamico:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/airtonneto.so -o $(BIN_DIR)/$@



#WINDOWS
airtonneto.lib: $(SRC_DIR)/lista.cpp $(INC_DIR)/biblio.h $(INC_DIR)/pilha.h $(INC_DIR)/lista.h $(INC_DIR)/fila.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/lista.cpp -o $(OBJ_DIR)/lista.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/lista.o
	@echo "+++ [Biblioteca estatica criada em $(LIB_DIR)/$@] +++"

airtonneto.dll: $(SRC_DIR)/lista.cpp $(INC_DIR)/biblio.h $(INC_DIR)/pilha.h $(INC_DIR)/lista.h $(INC_DIR)/fila.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/lista.cpp -o $(OBJ_DIR)/lista.o
	$(CC) -shared -o $(LIB_DIR)/$@ $(OBJ_DIR)/lista.o
	@echo "+++ [Biblioteca dinamica criada em $(LIB_DIR)/$@] +++"

prog_estatico.exe:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/airtonneto.lib -o $(BIN_DIR)/$@

prog_dinamico.exe:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/airtonneto.dll -o $(BIN_DIR)/$@

clean:
	@echo "Removendo arquivos objeto e executaveis/binarios..."
	@rm -rf $(OBJ_DIR)/*