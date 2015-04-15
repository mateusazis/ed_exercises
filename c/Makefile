FLAGS=-ansi

all: main.o
	gcc *.o -omain $(FLAGS)

main.o: list.o llist.o alist.o stack.o lstack.o main.c
	gcc main.c -c $(FLAGS)

stack.o: stack.c stack.h list.h
	gcc stack.c -c $(FLAGS)
astack.o: stack.h node.h
	gcc astack.c -c $(FLAGS)

list.o: node.o list.c list.h
	gcc list.c -c $(FLAGS)
llist.o: list.h
	gcc llist.c -c $(FLAGS)
alist.o: list.h
	gcc alist.c -c $(FLAGS)

node.o: node.c node.h
	gcc node.c -c $(FLAGS)