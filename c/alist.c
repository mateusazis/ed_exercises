#include "alist.h"
#include "node.h"
#include <stdlib.h>
#include <stdio.h>

#define GET_DATA(l) AListData* data = (AListData*)l->data;
#define max(a,b) (a > b ? a : b)

typedef struct {
    int capacity;
    ListValue_t *values;
} AListData;

static void alist_addi(List* l, int val){
    GET_DATA(l);

    if(l->size >= data->capacity){
        int newCap = max((int)(data->capacity * 1.1f), data->capacity + 10);
        data->values = (ListValue_t*)realloc(data->values, newCap*sizeof(ListValue_t));
        data->capacity = newCap;
        printf("Capacity to %d\n", newCap);
    }
    data->values[l->size].i = val;
    printf("added %d\n", val);
    l->size++;
}

static void alist_removeAt(List* l, int index){
    GET_DATA(l);

    int i;
    for(i = index + 1; i < l->size; i++)
        data->values[i-1].i = data->values[i].i;

    l->size--;
}

static void alist_print(List* l){
    GET_DATA(l);

    int i;
    printf("[");
    int first = 1;
    for(i = 0; i < l->size; i++){
      if(!first)
        printf(", ");
      printf("%d", data->values[i].i);
      first = 0;
    }
    puts("]");
}
static void alist_invert(List* l){
    GET_DATA(l);

    const int size = l->size;
    const int len = size / 2;
    int i, j = size - 1, temp;

    for(i = 0; i < len; i++, j--){
        temp = data->values[i].i;
        data->values[i].i = data->values[j].i;
        data->values[j].i = temp;
    }
}

static void alist_free(List* l){
    GET_DATA(l);

    free(data->values);
    free(data);
    free(l);
}

List* alist_new(){
    static _ListInterface implementation = {
        alist_addi,
        alist_removeAt,
        alist_print,
        alist_invert,
        alist_free
    };

    List* l = (List*)malloc(sizeof(List));

    AListData* data = (AListData*)malloc(sizeof(AListData));
    data->capacity = 0;
    data->values = NULL;

    l->data = data;
    l->size = 0;
    l->type = NONE;
    l->impl = &implementation;

    return l;
}