#include "stack.h"

void stack_pushi(Stack* s, int val){
  s->impl->pushi(s, val);
}
void stack_pop(Stack* s){
  s->impl->pop(s);
}

int stack_topi(Stack* s){
  return s->impl->topi(s);
}

void stack_free(Stack* s){
  s->impl->free(s);
}