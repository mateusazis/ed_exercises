#ifndef NODE_H
#define NODE_H

typedef struct Node Node;

typedef union {
    int i;
    double d;
    char* s;
    char c;
    void* p;
} ListValue_t;

struct Node {
  ListValue_t value;
  Node* next;
};


#endif