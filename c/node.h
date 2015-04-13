#ifndef NODE_H
#define NODE_H

typedef struct Node Node;

struct Node {
  union {
    int i;
    double d;
    char* s;
    char c;
    void* p;
  } value;
  Node* next;
};


#endif