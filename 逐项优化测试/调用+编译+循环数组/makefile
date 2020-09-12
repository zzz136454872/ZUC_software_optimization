CC = gcc
OPT= -Wall -O3 -Ofast -march=native -funroll-loops
TARGET=main.exe
all: $(TARGET)
	./main.exe
$(TARGET):main.c zuc.c
	$(CC) $< $(OPT) -o $@
