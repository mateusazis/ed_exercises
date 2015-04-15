#include "list.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define __MAIN__ stack_test

void t1(){
  List* l = llist_new();
  list_addi(l, 10);
  list_addi(l, 20);
  list_addi(l, 30);
  list_print(l);

  list_removeAt(l, 1);
  list_print(l);
  list_invert(l);
  list_print(l);
  list_free(l);
}

void t2(){
    List* l = alist_new();
    int i;
    for(i = 0; i < 15; i++)
        list_addi(l, i);
    list_print(l);

    list_removeAt(l, 1);
    list_removeAt(l, 7);
    list_print(l);
    list_invert(l);
    list_print(l);
    list_free(l);
}

void stack_test(){
    Stack* s = lstack_new();

    stack_pushi(s, 10);
    stack_pushi(s, 20);
    stack_pushi(s, 30);
    assert(stack_topi(s) == 30);
    stack_pop(s);
    assert(stack_topi(s) == 20);
    stack_pushi(s, 40);
    assert(stack_topi(s) == 40);
    stack_pop(s);
    assert(stack_topi(s) == 20);
    stack_pop(s);
    assert(stack_topi(s) == 10);
    stack_pop(s);

    stack_free(s);
}


extern void __MAIN__();

int main(){
  __MAIN__();
  return 0;
}