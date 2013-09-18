.PHONY: build clean debug rebuild

CC = gcc
FILES = Game.c Item.c Dictionary.c Command.c Player.c Room.c 
OUT_EXE = bin/Zuul
FLAGS = -Wall -ansi
SRC = $(addprefix src/, $(FILES))

build:	$(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(OUT_EXE)

clean:
	-rm -f *.o $(OUT_EXE)

debug:
	$(CC) -g $(FLAGS) $(SRC) -o $(OUT_EXE)

rebuild: clean build
