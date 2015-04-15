#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

#define max(a,b) (a > b ? a : b)

typedef struct {
  ListValue_t* values;
  int capacity;
} AStackData;

#define GET_DATA(v, l) v = (AStackData*)l->data;

static void astack_pushi(Stack* s, int val){
  GET_DATA(AStackData* data, s);

  if(s->size == data->capacity){
    int newCap = max((int)(data->capacity * 1.1f), data->capacity + 10);
    data->values = (ListValue_t*)realloc(data->values, newCap*sizeof(ListValue_t));
    data->capacity = newCap;
  }

  data->values[s->size].i = val;
  s->size++;
}
static void astack_pop(Stack* s){
  GET_DATA(AStackData* data, s);

  s->size--;
}

static int astack_topi(Stack* s){
  GET_DATA(AStackData* data, s);

  return data->values[s->size-1].i;
}

static void astack_free(Stack* s){
  GET_DATA(AStackData* data, s);
  free(s->data);
  free(s);
}

Stack* astack_new(){
    static _StackInterface implementation = {
        astack_pushi,
        astack_pop,
        astack_topi,
        astack_free,
    };

    Stack* s = (Stack*)malloc(sizeof(Stack));
    AStackData* data = (AStackData*)malloc(sizeof(AStackData));
    data->capacity = 0;
    data->values = NULL;

    s->data = data;
    s->type = NONE;
    s->impl = &implementation;
    s->size = 0;

    return s;
}