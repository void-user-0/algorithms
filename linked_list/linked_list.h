/*
  {LinkedList Node Structure}

  void *data;            element node
  struct ll_node *next;  pointer to next node
*/
struct ll_node {
  void *data;
  struct ll_node *next;
};


/*
  [Linked List Structure]
  unsigned int len;       size LinkedList
  struct ll_node *head;   pointer from head LinkedList
  struct ll_node *tail;   pointer from tail LinkedList

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
    new_ll: allocate memmory from linked list, init fields, return linked list
    new_ll_node: allocate memmory from linked list node, init fields, return linked list node
    ll_insert_node: insert node from linked list
    ll_delete_node: delete node from linked list
    ll_search_node: search node from linked list
  }
*/
struct ll *new_ll();
struct ll_node *new_ll_node(struct ll *ll, void *data);
struct ll_node *ll_search_node(struct ll *ll, void *data);
void ll_insert_node_head(struct ll *ll, void *data);
void ll_insert_node(struct ll *ll, void *data);
void ll_delete_node(struct ll *ll, void *data);
void ll_clean(struct ll *ll);
void ll_destroy(struct ll *ll);
