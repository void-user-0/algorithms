#ifndef doubly_linked_list_h
#define doubly_linked_list_h

#include <stdbool.h>

struct doubly_linked_list_node;

struct doubly_linked_list_node {
  void *data;
  struct doubly_linked_list_node *next;
  struct doubly_linked_list_node *prev;
};

struct doubly_linked_list {
  struct doubly_linked_list_node *head;
  struct doubly_linked_list_node *tail;
};

struct doubly_linked_list_node *doubly_linked_list_search(struct doubly_linked_list *doubly_linked_list, void *data);
struct doubly_linked_list_node *new_doubly_linked_list_node(void *data);
struct doubly_linked_list *new_doubly_linked_list();

bool doubly_linked_list_check_empty(struct doubly_linked_list *doubly_linked_list);
bool doubly_linked_list_clean(struct doubly_linked_list *doubly_linked_list);
bool doubly_linked_list_destroy(struct doubly_linked_list *doubly_linked_list);
bool doubly_linked_list_insert_head(struct doubly_linked_list *doubly_linked_list, void *data);
bool doubly_linked_list_insert_tail(struct doubly_linked_list *doubly_linked_list, void *data);
bool doubly_linked_list_delete_node(struct doubly_linked_list *doubly_linked_list, void *data);
#endif
