FLAGS=-ansi

MAIN_DEPS=main.o list.o llist.o alist.o stack.o lstack.o astack.o node.o queue.o lqueue.o aqueue.o

all: $(MAIN_DEPS)
	gcc $(MAIN_DEPS) -omain $(FLAGS)

main.o: main.c list.h stack.h
	gcc main.c -c $(FLAGS)

stack.o: stack.c stack.h list.h
	gcc stack.c -c $(FLAGS)
astack.o: stack.h node.h astack.c
	gcc astack.c -c $(FLAGS)
lstack.o: stack.h node.h lstack.c
	gcc lstack.c -c $(FLAGS)

queue.o: queue.c queue.h list.h
	gcc queue.c -c $(FLAGS)
lqueue.o: queue.h node.h lqueue.c
	gcc lqueue.c -c $(FLAGS)
aqueue.o: queue.h node.h aqueue.c
	gcc aqueue.c -c $(FLAGS)

list.o: list.c list.h
	gcc list.c -c $(FLAGS)
llist.o: list.h llist.c
	gcc llist.c -c $(FLAGS)
alist.o: list.h alist.c
	gcc alist.c -c $(FLAGS)

node.o: node.c node.h
	gcc node.c -c $(FLAGS)