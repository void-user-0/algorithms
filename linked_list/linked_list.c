#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

void err(const char *message) {
  fprintf(stderr, "[ERROR]: %s\n", message);
  exit(1);
}

void ll_destroy(struct ll *ll) {
  struct ll_node *node = ll->head;
  if (ll->head) {
    ll_clean(ll);
  }
  free(ll);
}

void ll_clean(struct ll *ll) {
  if (!ll->head) {
    err("list empty!");
  }
  
  struct ll_node *node = ll->head;
  struct ll_node *temp = NULL;
  while (node != NULL) {
    temp = node->next;
    free(node);
    node = temp;
  }
  ll->head = ll->tail = NULL;
  ll->len = 0;
}

struct ll *new_ll()
{
  struct ll *ll = (struct ll *)malloc(sizeof(struct ll));

  if (!ll) {
    err("fail create linked list!");
  }

  ll->tail = ll->head = NULL;
  ll->len = 0;

  return ll;
}

struct ll_node *new_ll_node(void *data)
{
  struct ll_node *ll_node = (struct ll_node *)malloc(sizeof(struct ll_node));

  if (!ll_node) {
    err("fail create node!");
  }

  ll_node->data = data;
  ll_node->next = NULL;

  return ll_node;
}

void ll_insert_node_head(struct ll *ll, void *data)
{
  struct ll_node *node = new_ll_node(data);

  if (!node) {
    err("fail create node");
  }

  if (!ll->head) {
    ll->head = ll->tail = node;
    ll->len++;
    return;   
  }

  node->next = ll->head;
  ll->head = node;
  ll->len++;
}

void ll_insert_node_tail(struct ll *ll, void *data)
{
  struct ll_node *node = new_ll_node(data);

  if (!node) {
    err("fail create node!");
  }

  if (ll->head == NULL && ll->tail == NULL) {
    ll->head = ll->tail = node;
    ll->len++;
    return;
  }

  ll->tail->next = node;
  ll->tail = ll->tail->next;
  ll->len++;
}

struct ll_node *ll_search_node(struct ll *ll, void *data) {
  if (!ll->head) {
    err("list empty");
  }

  struct ll_node *node = ll->head;
  while (node != NULL) {
    if (node->data == data) {
      return node;
    }
    node = node->next;
  }
  
  return NULL;
}

void ll_delete_node(struct ll *ll, void *data)
{
  if (!ll->head) {
    err("list empty!");
  }

  if (ll->head == ll->tail) {
    free(ll->head);
    ll->tail = ll->head = NULL;
    return;
  }

  struct ll_node *node = ll->head;
  struct ll_node *prev = NULL;
  struct ll_node *temp = NULL;

  while (node != NULL) {
    if (node->data == data) {
      if (prev == NULL) {
        ll->head = node->next;
        if (node->next == ll->tail) {
          ll->tail = ll->head; 
        }
      } else if (node->next == NULL) {
        ll->tail = prev;
      } else {
        prev->next = node->next;
      }
      
      temp = node->next;
      free(node);
      ll->len--;
      node = temp;
      continue;
    }
    prev = node;
    node = node->next;
  }
}
