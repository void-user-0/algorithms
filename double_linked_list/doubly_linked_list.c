#include <stdlib.h>
#include "doubly_linked_list.h"

struct doubly_linked_list_node *new_doubly_linked_list_node(void *data)
{
  struct doubly_linked_list_node *doubly_linked_list_node = (struct doubly_linked_list_node *)malloc(sizeof(struct doubly_linked_list_node));
  if (!doubly_linked_list_node) {
    return NULL;
  }

  doubly_linked_list_node->data = data;
  doubly_linked_list_node->next = doubly_linked_list_node->prev = NULL;
  return doubly_linked_list_node;
}

struct doubly_linked_list *new_doubly_linked_list()
{
  struct doubly_linked_list *doubly_linked_list = (struct doubly_linked_list *)malloc(sizeof(struct doubly_linked_list));
  if (!doubly_linked_list) {
    return NULL;
  }

  doubly_linked_list->head = doubly_linked_list->tail = NULL;
  return doubly_linked_list;
}

bool doubly_linked_list_destroy(struct doubly_linked_list *doubly_linked_list)
{
  doubly_linked_list_clean(doubly_linked_list);
  free(doubly_linked_list);
  return true;
}

bool doubly_linked_list_clean(struct doubly_linked_list *doubly_linked_list)
{
  if (!doubly_linked_list->head) {
    return false;
  }

  struct doubly_linked_list_node *doubly_linked_list_node = doubly_linked_list->head;
  struct doubly_linked_list_node *temp;
  while (doubly_linked_list_node != NULL) {
    temp = doubly_linked_list_node->next;
    free(doubly_linked_list_node);
    doubly_linked_list_node = temp;
  }
  return true;
}

bool check_empty_doubly_linked_list(struct doubly_linked_list *doubly_linked_list)
{
  if (!doubly_linked_list->head) return false;
  return true;
}

bool doubly_linked_list_insert_head(struct doubly_linked_list *doubly_linked_list, void *data)
{
  struct doubly_linked_list_node *doubly_linked_list_node = new_doubly_linked_list_node(data);
  if (!check_empty_doubly_linked_list(doubly_linked_list)) {
    doubly_linked_list->head = doubly_linked_list->tail = doubly_linked_list_node;
    return true;
  }
  else {
    doubly_linked_list_node->next = doubly_linked_list->head;
    doubly_linked_list->head = doubly_linked_list_node;
    doubly_linked_list->head->next->prev = doubly_linked_list->head;
    return true;
  }

  return false;
}

bool doubly_linked_list_insert_tail(struct doubly_linked_list *doubly_linked_list, void *data)
{
  struct doubly_linked_list_node *doubly_linked_list_node = new_doubly_linked_list_node(data);
  if (!check_empty_doubly_linked_list(doubly_linked_list)) {
    doubly_linked_list->head = doubly_linked_list->tail = doubly_linked_list_node;
    return true;
  }
  else {
    doubly_linked_list->tail->next = doubly_linked_list_node;
    doubly_linked_list_node->prev = doubly_linked_list->tail;
    doubly_linked_list->tail = doubly_linked_list->tail->next;
    return true;
  }

  return false;
}

struct doubly_linked_list_node *doubly_linked_list_search(struct doubly_linked_list *doubly_linked_list, void *data)
{
  if (!check_empty_doubly_linked_list(doubly_linked_list)) {
    return false;
  }

  else {
    struct doubly_linked_list_node *doubly_linked_list_node = doubly_linked_list->head;
    while (doubly_linked_list_node != NULL) {
      if (doubly_linked_list_node->data == data) {
        return doubly_linked_list_node;
      }
      doubly_linked_list_node = doubly_linked_list_node->next;
    }
  }
  return false;
}

bool doubly_linked_list_delete_node(struct doubly_linked_list *doubly_linked_list, void *data)
{
  if (!check_empty_doubly_linked_list(doubly_linked_list)) {
    return false;
  }

  else if (doubly_linked_list->head == doubly_linked_list->tail) {
    free(doubly_linked_list->head);
    doubly_linked_list->head = doubly_linked_list->tail = NULL;
    return true;
  }

  else {
    struct doubly_linked_list_node *doubly_linked_list_node = doubly_linked_list->head;
    struct doubly_linked_list_node *temp;

    while (doubly_linked_list_node != NULL) {
      if (doubly_linked_list_node->data == data) {

        if (doubly_linked_list_node == doubly_linked_list->head) {
          doubly_linked_list->head = doubly_linked_list->head->next;
          if (doubly_linked_list->head == doubly_linked_list->tail) {
            doubly_linked_list->tail = doubly_linked_list->head;
          }
        }        
  
        else if (doubly_linked_list_node == doubly_linked_list->tail) {
          doubly_linked_list->tail = doubly_linked_list_node->prev;
          if (doubly_linked_list->tail == doubly_linked_list->head) {
            doubly_linked_list->head = doubly_linked_list->tail;
          }
        }

        else {
          doubly_linked_list_node->prev->next = doubly_linked_list_node->next;
          doubly_linked_list_node->next->prev = doubly_linked_list_node->prev;
        }
        
        temp = doubly_linked_list_node->next;
        free(doubly_linked_list_node);
        doubly_linked_list_node = temp;
        continue;
      }
      
      doubly_linked_list_node = doubly_linked_list_node->next;
    }
  }
  return true;
}
