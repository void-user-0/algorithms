#ifndef linked_list_h
#define linked_list_h

/*
  {LinkedList Node Structure}

  void *data;            element node [data{"Hello World"}]
  struct ll_node *next;  pointer to next node
*/
struct ll_node {
  void *data;
  struct ll_node *next;
};


/*
  [Linked List Structure]
  unsigned int len;       number of elements in the list
  struct ll_node *head;   pointer to the beginning of the list
  struct ll_node *tail;   pointer to the end of the list

  [Example Structure LinkedList]
  * - pointer to next node
  NULL <- [head node][*] -> [node][*] -> [tail node][*] -> NULL
*/
struct ll {
  unsigned int len;
  struct ll_node *head;
  struct ll_node *tail;
};


/*
  functions {
    new_ll: allocates memory for a linked list, fills in the fields and returns a pointer to the linked list
    new_ll_node: allocates memory for a new node, fills in the fields, and returns a pointer to the new node
    ll_insert_node_head: insert node at beginning
    ll_insert_node_tail: insert node at the end
    ll_delete_node: removes all matching nodes
    ll_search_node: searches for and returns a pointer to a node
    ll_destroy: deletes a linked list object and all its nodes
  }
*/

void ll_insert_node_head(struct ll *ll, void *data);
void ll_insert_node_tail(struct ll *ll, void *data);
void ll_delete_node(struct ll *ll, void *data);
void ll_destroy(struct ll *ll);
void ll_clean(struct ll *ll);

struct ll *new_ll();
struct ll_node *new_ll_node(void *data);
struct ll_node *ll_search_node(struct ll *ll, void *data);

#endif
