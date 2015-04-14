#include "list.h"
#include "llist.h"
#include <stdio.h>
#include <stdlib.h>

#define __MAIN__ t1

void t1(){
  List* l = llist_new();
  list_addi(l, 10);
  list_addi(l, 20);
  list_addi(l, 30);
  int i;
  for(i = 0; i < 10000000; i++){
      list_addi(l, i);
  }
  char t[100];
  // list_print(l);

  puts("enter");
  gets(t);
  // list_removeAt(l, 1);
  // list_print(l);
  // list_invert(l);
  // list_print(l);
  list_free(l);
  puts("enter");
  gets(t);
}

void t2(){
  List* l = llist_new();
  int i;
  for(i = 0; i < 100; i++)
    list_addi(l, i);
    char a;
  gets(&a);
  list_print(l);
  gets(&a);
  list_invert(l);
  gets(&a);
  list_print(l);
  gets(&a);
  list_removeAt(l, 1);
  gets(&a);
  list_print(l);
  list_free(l);
}


extern void __MAIN__();

int main(){
  __MAIN__();
  return 0;
}