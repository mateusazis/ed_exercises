#ifndef STACK_H
#define STACK_H

#include "node.h"
#include "list.h"

typedef struct Stack Stack;

typedef struct {
  void (*pushi)(Stack* s, int val);
  void (*pop)(Stack* s);
  int (*topi)(Stack* s);
  void (*free)(Stack* s);
} _StackInterface;

struct Stack{
  void* data;

  int size;
  ListType type;
  _StackInterface* impl;
};

extern Stack* astack_new();
extern Stack* lstack_new();

extern void stack_pushi(Stack* s, int val);
extern void stack_pop(Stack* s);
extern int stack_topi(Stack* s);
extern void stack_free(Stack* s);

#endif /* STACK_H */