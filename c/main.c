#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define __MAIN__ t2

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


extern void __MAIN__();

int main(){
  __MAIN__();
  return 0;
}