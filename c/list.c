#include "list.h"
#include <stdlib.h>
#include <stdio.h>

List* list_new(){
  List* l = (List*)malloc(sizeof(List));

  l->first = NULL;
  l->size = 0;
  l->type = NONE;

  return l;
}

void list_addi(List* l, int val){
  Node* n = l->first;
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->value.i = val;
  new_node->next = NULL;
  while(n && n->next)
    n = n->next;

  if(n)
    n->next = new_node;
  else
    l->first = new_node;
  l->size++;
}

void list_removeAt(List* l, int index){
  Node* toRemove;
  if(index == 0){
    Node* toRemove = l->first;
    l->first = toRemove->next;
    free(toRemove);
  } else {
    Node* n = l->first;
    while(index-- > 1){
      n = n->next;
    }
    toRemove = n->next;
    n->next = toRemove->next;
    free(toRemove);
  }
  l->size--;
}

void list_print(List* l){
  Node* n = l->first;
  printf("[");
  int first = 1;
  while(n){
    if(!first)
      printf(", ");
    printf("%d", n->value.i);
    n = n->next;
    first = 0;
  }
  puts("]");
}

void list_invert(List* l){
  Node* ant = NULL, *last, *cur, *next;
  cur = l->first;
  while(cur){
    next = cur->next;
    cur->next = ant;
    ant = cur;
    cur = next;
  }
  l->first = ant;
}

void list_free(List* l){
  free(l);
}