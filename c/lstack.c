#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

#define GET_DATA(v, l) v = (Node*)l->data;

static void lstack_pushi(Stack* s, int val){
  GET_DATA(Node* n, s);

  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->value.i = val;
  new_node->next = n;

  s->data = new_node;
  s->size++;
}
static void lstack_pop(Stack* s){
  GET_DATA(Node* n, s);

  s->data = n->next;
  s->size--;

  free(n);
}

static int lstack_topi(Stack* s){
  GET_DATA(Node* n, s);

  return n->value.i;
}

static void lstack_free(Stack* s){
  GET_DATA(Node* n, s);
  Node* old;

  while(n){
    old = n;
    n = n->next;
    free(old);
  }

  free(s);
}

Stack* lstack_new(){
    static _StackInterface implementation = {
        lstack_pushi,
        lstack_pop,
        lstack_topi,
        lstack_free,
    };

    Stack* s = (Stack*)malloc(sizeof(Stack));

    s->data = NULL;
    s->type = NONE;
    s->impl = &implementation;
    s->size = 0;

    return s;
}