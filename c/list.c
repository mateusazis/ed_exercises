#include "list.h"

void list_addi(List* l, int val){
    l->impl->addi(l, val);
}

void list_removeAt(List* l, int index){
    l->impl->removeAt(l, index);
}

void list_print(List* l){
    l->impl->print(l);
}

void list_invert(List* l){
    l->impl->invert(l);
}

void list_free(List* l){
  l->impl->free(l);
}