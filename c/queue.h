#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"
#include "list.h"

typedef struct Queue Queue;

typedef struct {
  void (*addi)(Queue* s, int val);
  void (*remove)(Queue* s);
  int (*fronti)(Queue* s);
  void (*free)(Queue* s);
} _QueueInterface;

struct Queue{
  void* data;

  int size;
  ListType type;
  _QueueInterface* impl;
};

extern Queue* aqueue_new();
extern Queue* lqueue_new();

extern void queue_addi(Queue* q, int val);
extern void queue_remove(Queue* q);
extern int queue_fronti(Queue* q);
extern void queue_free(Queue* q);

#endif /* QUEUE_H */