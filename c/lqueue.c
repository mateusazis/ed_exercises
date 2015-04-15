#include <stdlib.h>
#include <stdio.h>

#include "queue.h"
#include "list.h"

#define GET_DATA(decl, q) decl = (List*)q->data;

static void lqueue_addi(Queue* q, int val){
  GET_DATA(List* l, q)

  list_addi(l, val);

  q->size++;
}
static void lqueue_remove(Queue* q){
  GET_DATA(List* l, q)

  list_removeAt(l, 0);
  q->size--;
}

static int lqueue_fronti(Queue* q){
  GET_DATA(List* l, q)

  return list_geti(l, 0);
}

static void lqueue_free(Queue* q){
  GET_DATA(List* l, q)

  list_free(l);
  free(q);
}

Queue* lqueue_new(){
    static _QueueInterface implementation = {
        lqueue_addi,
        lqueue_remove,
        lqueue_fronti,
        lqueue_free,
    };

    Queue* s = (Queue*)malloc(sizeof(Queue));

    s->data = llist_new();
    s->type = NONE;
    s->impl = &implementation;
    s->size = 0;

    return s;
}