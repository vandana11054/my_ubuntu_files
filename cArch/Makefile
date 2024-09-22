# This is a comment line
CC=g++
# CFLAGS will be the options passed to the compiler.
CFLAGS=-c -Wall
OBJECTS = main.o factorial.o
all: prog

prog: $(OBJECTS)
	$(CC) $(OBJECTS) -o prog

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o prog
