#include "queue.h"

void queue_addi(Queue* q, int val){
  q->impl->addi(q, val);
}
void queue_remove(Queue* q){
  q->impl->remove(q);
}

int queue_fronti(Queue* q){
  return q->impl->fronti(q);
}

void queue_free(Queue* q){
  q->impl->free(q);
}