CC = gcc -Wall
OPT=-O3 -Ofast -march=native -funroll-loops -mavx2
TARGET=main.exe
$(TARGET):main.c zuc.c
	$(CC) $< $(OPT) -o $@
