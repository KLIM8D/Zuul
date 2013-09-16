.PHONY: build clean rebuild

CC = gcc
FILES = src/*.c 
OUT_EXE = bin/Zuul
FLAGS = -Wall -ansi

build:	$(FILES)
	$(CC) $(FLAGS) $(FILES) -o $(OUT_EXE)

clean:	
	-rm -f *.o $(OUT_EXE)

rebuild:
	clean build
