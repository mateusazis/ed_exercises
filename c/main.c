#include "list.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define assert_this(a) assert(a); test_count++;
#define LIST_TEST(l, ...) void list_test(){\
  {List* l = llist_new(); __VA_ARGS__ }\
  {List* l = alist_new(); __VA_ARGS__ }\
}

#define __MAIN__ list_test

static int test_count = 0;

LIST_TEST(l,
  list_addi(l, 10);
  list_addi(l, 20);
  list_addi(l, 30);

  assert_this(list_geti(l, 0) == 10);
  assert_this(list_geti(l, 1) == 20);
  assert_this(list_geti(l, 2) == 30);

  list_removeAt(l, 1);
  assert_this(list_geti(l, 0) == 10);
  assert_this(list_geti(l, 1) == 30);

  list_invert(l);
  assert_this(list_geti(l, 0) == 30);
  assert_this(list_geti(l, 1) == 10);

  assert_this(l->size == 2);

  list_free(l);
)

void stack_test(){
    Stack* s = lstack_new();

    stack_pushi(s, 10);
    stack_pushi(s, 20);
    stack_pushi(s, 30);
    assert_this(stack_topi(s) == 30);
    stack_pop(s);
    assert_this(stack_topi(s) == 20);
    stack_pushi(s, 40);
    assert_this(stack_topi(s) == 40);
    stack_pop(s);
    assert_this(stack_topi(s) == 20);
    stack_pop(s);
    assert_this(stack_topi(s) == 10);
    stack_pop(s);

    stack_free(s);
}


extern void __MAIN__();

int main(){
  __MAIN__();
  printf("Finished with %d successful assertions.\n", test_count);
  return 0;
}