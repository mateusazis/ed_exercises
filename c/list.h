#ifndef LIST_H
#define LIST_H

#include "node.h"

typedef enum { INTEGER, DOUBLE, STRING, POINTER, NONE } ListType;

typedef struct List List;

typedef struct {
    void (*addi)(List* l, int val);
    void (*removeAt)(List* l, int index);
    void (*print)(List* l);
    void (*invert)(List* l);
    void (*free)(List* l);
} _ListInterface;

struct List{
  void* data;

  int size;
  ListType type;
  _ListInterface* impl;
};

extern List* llist_new();
extern List* alist_new();

extern void list_addi(List* l, int val);
extern void list_removeAt(List* l, int index);
extern void list_print(List* l);
extern void list_invert(List* l);
extern void list_free(List* l);

#endif