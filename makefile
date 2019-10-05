SRC_DEP=src/
OBJ_DEP=obj/*.o
OBJ_DIR=obj/
BIN_DIR=bin/

compile:
	g++ -I src/include -c $(SRC_DEP)main.cpp -o $(OBJ_DIR)main.o
	g++ -I src/include -c $(SRC_DEP)Image.cpp -o $(OBJ_DIR)Image.o

link: $(OBJ_DEP)
	g++ -I src/include -o $(BIN_DIR)terrain $(OBJ_DEP)
