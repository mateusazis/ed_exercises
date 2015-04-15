#include <stdlib.h>
#include <stdio.h>

#include "Queue.h"

#define AQUEUE_CAPACITY 2048
#define GET_DATA(v, l) v = (AQueueData*)l->data;
#define max(a,b) (a > b ? a : b)

typedef struct {
  ListValue_t* values;
  int start, end;
} AQueueData;


static void aqueue_addi(Queue* q, int val){
  GET_DATA(AQueueData* data, q);

  data->values[data->end].i = val;

  data->end++;
  q->size++;
}
static void aqueue_remove(Queue* q){
  GET_DATA(AQueueData* data, q);

  data->start = (data->start + 1) % AQUEUE_CAPACITY;

  q->size--;
}

static int aqueue_fronti(Queue* q){
  GET_DATA(AQueueData* data, q);

  return data->values[data->start].i;
}

static void aqueue_free(Queue* q){
  GET_DATA(AQueueData* data, q);

  free(data->values);
  free(q->data);
  free(q);
}

Queue* aqueue_new(){
    static _QueueInterface implementation = {
        aqueue_addi,
        aqueue_remove,
        aqueue_fronti,
        aqueue_free,
    };

    Queue* q = (Queue*)malloc(sizeof(Queue));
    AQueueData* data = (AQueueData*)malloc(sizeof(AQueueData));
    data->values = (ListValue_t*)calloc(AQUEUE_CAPACITY, sizeof(ListValue_t));
    data->start = data->end = 0;

    q->data = data;
    q->type = NONE;
    q->impl = &implementation;
    q->size = 0;

    return q;
}