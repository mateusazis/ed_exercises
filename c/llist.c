#include "llist.h"
#include <stdlib.h>
#include <stdio.h>

#define GET_DATA(l) LListData* data = (LListData*)l->data;

typedef struct {
    Node* first, *last;
} LListData;

static void llist_addi(List* l, int val){
    GET_DATA(l);

    Node* n = data->first;
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value.i = val;
    new_node->next = NULL;
    while(n && n->next)
      n = n->next;

    if(n)
      n->next = new_node;
    else
      data->first = new_node;
    l->size++;
}

static void llist_removeAt(List* l, int index){
    GET_DATA(l);

    Node* toRemove;
    if(index == 0){
      Node* toRemove = data->first;
      data->first = toRemove->next;
      free(toRemove);
    } else {
      Node* n = data->first;
      while(index-- > 1){
        n = n->next;
      }
      toRemove = n->next;
      n->next = toRemove->next;
      free(toRemove);
    }
    l->size--;
}

static void llist_print(List* l){
    GET_DATA(l);

    Node* n = data->first;
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
static void llist_invert(List* l){
    GET_DATA(l);
    Node* ant = NULL, *last, *cur, *next;
    cur = data->first;
    while(cur){
        next = cur->next;
        cur->next = ant;
        ant = cur;
        cur = next;
    }
    data->first = ant;
}

static void llist_free(List* l){
    GET_DATA(l);
    Node* n = data->first;
    while(n){
        Node* old = n;
        n = n->next;
        free(old);
        /* may also need to clean its value */
    }
    free(data);
    free(l);
}

List* llist_new(){
    static _ListInterface implementation = {
        llist_addi,
        llist_removeAt,
        llist_print,
        llist_invert,
        llist_free
    };

    List* l = (List*)malloc(sizeof(List));

    LListData* data = (LListData*)malloc(sizeof(LListData));
    data->first = data->last = NULL;

    l->data = data;
    l->size = 0;
    l->type = NONE;
    l->impl = &implementation;

    return l;
}