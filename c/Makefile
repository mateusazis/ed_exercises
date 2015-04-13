FLAGS=-ansi

all: main.o
	gcc main.o list.o node.o -omain $(FLAGS)

main.o: list.o main.c list.h
	gcc main.c -c $(FLAGS)

list.o: node.o list.c list.h
	gcc list.c -c $(FLAGS)

node.o: node.c node.h
	gcc node.c -c $(FLAGS)