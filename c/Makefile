FLAGS=-ansi

all: list.o main.c
	gcc main.c list.o node.o -omain $(FLAGS)

list.o: node.o list.c list.h
	gcc list.c -c

node.o: node.c node.h
	gcc node.c -c