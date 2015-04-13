#ifndef LIST_H
#define LIST_H

#include "node.h"

typedef enum { INTEGER, DOUBLE, STRING, POINTER, NONE } ListType;

typedef struct {
  Node* first;
  int size;
  ListType type;
} List;

extern List* list_new();
extern void list_addi(List* l, int val);
extern void list_removeAt(List* l, int index);
extern void list_print(List* l);
extern void list_invert(List* l);
extern void list_free(List* l);

#endif