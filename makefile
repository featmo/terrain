SRC_DEP=src/
SRC_ALL=src/main.cpp src/Image.cpp src/ProTexture.cpp
OBJ_DEP=obj/*.o
OBJ_DIR=obj/
BIN_DIR=bin/terrain
INCLUDE=-IC:/mingw_dev_lib/include/SDL2
LIBRARY=-LC:/mingw_dev_lib/lib
LINK_FLAGS=-w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 

all:
	g++ -std=c++17 $(SRC_ALL) $(INCLUDE) $(LIBRARY) $(LINK_FLAGS) -o $(BIN_DIR)

compile:
	g++ -c -IC:\mingw_dev_lib\include\SDL2 $(SRC_DEP)main.cpp -o $(OBJ_DIR)main.o
	g++ -c $(SRC_DEP)Image.cpp -o $(OBJ_DIR)Image.o
	g++ -c $(SRC_DEP)ProTexture.cpp -o $(OBJ_DIR)ProTexture.o

link: $(OBJ_DEP)
	g++ -o $(BIN_DIR)terrain $(LINK_FLAGS) $(OBJ_DEP) -LC:\mingw_dev_lib\lib
