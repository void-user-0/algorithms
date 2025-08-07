#include <stdio.h>
#include "doubly_linked_list.h"

// Usage doubly linked list lib

int main(int argc, char *argv[])
{ 
  struct doubly_linked_list *dll = new_doubly_linked_list();
  char *names[] = { "John", "Alice" };
  float num = 1.2;
  
  doubly_linked_list_insert_head(dll, names);
  doubly_linked_list_insert_tail(dll, (int *)10);
  doubly_linked_list_insert_head(dll, "Hello World");
  doubly_linked_list_insert_tail(dll, &num);

  doubly_linked_list_delete_node(dll, (int *)10);
  doubly_linked_list_delete_node(dll, &num);

  doubly_linked_list_insert_head(dll, (int *)120);

  struct doubly_linked_list_node *dll_node = doubly_linked_list_search(dll, names);
  printf("%s\n", ((char **)dll_node->data)[0]);
  dll_node = doubly_linked_list_search(dll, "Hello World");
  printf("%s\n", (char *)dll_node->data);
  dll_node = doubly_linked_list_search(dll, (int *)120);
  printf("%d\n", dll_node->data);
  
  return 0;
}
