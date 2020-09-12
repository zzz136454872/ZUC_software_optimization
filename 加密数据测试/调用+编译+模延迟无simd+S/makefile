CC = gcc
OPT= -Wall -O3 -Ofast -march=native -funroll-loops
TARGET=main.exe
all: $(TARGET)
	./main.exe
$(TARGET):main.c zuc.c eea3.c
	$(CC) $< $(OPT) -o $@
