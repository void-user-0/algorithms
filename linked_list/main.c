#include "linked_list.h"


int main(int argc, char *argv[])
{
  struct ll *ll = new_ll();
  struct ll_node *f_node;

  char *names[] = {"Alice", "John", "Charli"};
  char names2[] = {"a b c d e f g"};
  int numbers[] = {1, 2, 3, 4, 5};
  
  ll_insert_node(ll, (int *)5);
  ll_insert_node(ll, (char *)"hello world");
  ll_insert_node(ll, names);
  ll_insert_node(ll, names2);
  ll_insert_node(ll, numbers);

  ll_insert_node_head(ll, "hello planet");

  ll_delete_node(ll, names);
  ll_clean(ll);
  ll_destroy(ll);
  
  return 0;
}
