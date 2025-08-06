#include "linked_list.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
  struct ll *ll = new_ll();
  struct ll_node *node = NULL;

  // types
  char *str_data = "hello world";
  char char_data = '*';
  char *names[] = {"Alice", "John", "Bob", NULL};

  int int_data = 25;
  int int_arr_data[] = {1, 2, 3, 4, 5};

  float num_float = 1.2;

  ll_insert_node_head(ll, str_data);
  ll_insert_node_head(ll, &int_data);
  ll_insert_node_tail(ll, int_arr_data);
  ll_insert_node_tail(ll, &char_data);
  ll_insert_node_head(ll, names);
  ll_insert_node_tail(ll, &num_float);

  node = ll_search_node(ll, &char_data);
  printf("%c\n", *(char *)node->data);
  node = ll_search_node(ll, str_data);
  printf("%s\n", (char *)node->data);
  node = ll_search_node(ll, &int_data);
  printf("%d\n", *(int *)node->data);
  node = ll_search_node(ll, int_arr_data);
  for (int i = 0;;i++) {
    if (!((int *)node->data)[i]) {
      break;
    }
    printf("%d\n", ((int *)node->data)[i]);
  }
  node = ll_search_node(ll, names);
  for (int i = 0;; i++) {
    if (!((char **)node->data)[i]) {
      break;
    }
    printf("name: %s\n", ((char **)node->data)[i]);
  }
  node = ll_search_node(ll, &num_float);
  printf("%f\n", *(float *)node->data);

  ll_delete_node(ll, names);
  printf("%d\n", ll->len);

  ll_destroy(ll);
   
  return 0;
}
