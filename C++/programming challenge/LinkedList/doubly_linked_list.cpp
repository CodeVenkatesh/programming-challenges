//doubly linked list implementation
#include <iostream>
using namespace std;

//struct for doubly linked list elements
typedef struct d_list_element
{
  void *data;
  struct d_list_element *prev;
  struct d_list_element *next;
} d_elem;

//struct for doubly linked list
typedef struct d_linked_list
{
  int size;
  int *match(const void *key1, const void *key2);
  void *destroy(void *data);
  d_elem *head;
  d_elem *tail;
} d_list;

//functions are essentially the same as in linked_list, but performed for doubly linked lists

void dlist_init(d_list *list, void *destroy(void *data));

void dlist_destroy(d_list *list);

bool dlist_insert_prev(d_list *list, d_elem *element, const void *data);

bool dlist_insert_next(d_list *list, d_elem *element, const void *data);

bool dlist_remove(d_list *list, d_elem *element, const void **data);

#define dlist_size(list) ((list)->size)

#define dlist_head(list) ((list)->head)

#define dlist_tail(list) ((list)->tail)

#define is_head(list, element) ((element)->prev == NULL ? 1 : 0)

#define is_tail(list, element) ((element)->next == NULL ? 1 : 0)

#define dlist_data(element) ((element)->data)

#define dlist_next(element) ((element)->next)

#define dlist_prev(element) ((element)->prev)

void dlist_init(d_list *list, void *destroy(void *data))
{
  list->size = 0;
  list->destroy = destroy;
  list->head = NULL;
  list->tail = NULL;
}

void dlist_destroy(d_list *list)
{
  void *data;
  while(dlist_size(list) > 0)
  {
    if(dlist_remove(list, dlist_tail(list), (void **) &data) == 0 && list->destroy != NULL)
    {
      list->destroy(data);
    }
  }

  memset(list, 0, sizeof(d_list));
}

bool dlist_insert_prev(d_list *list, d_elem *element, const void *data)
{
  d_elem *new_element;
  if(element == NULL && dlist_size(list) != 0)
  {
    return false;
  }

  if((new_element = (d_elem *)malloc(sizeof(d_elem))) == NULL)
  {
    return false;
  }

  new_element->data = (void *) data;

  if(dlist_size(list) == 0)
  {
    list->head = new_element;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = new_element;
  }

  else
  {
    new_element->next = element;
    new_element->prev = element->prev;

    if(element->next == NULL)
    {
      list->head = new_element;
    }

    else
    {
      element->prev->next = new_element;
    }

    element->prev = new_element;
  }

  list->size++;
  return true;
}

bool dlist_insert_next(d_list *list, d_elem *element, const void *data)
{
  d_elem *new_element;
  if(element == NULL && dlist_size(list) != 0)
  {
    return false;
  }

  if((new_element = (d_elem *)malloc(sizeof(d_elem))) == NULL)
  {
    return false;
  }

  new_element->data = (void *) data;

  if(dlist_size(list) == 0)
  {
    list->head = new_element;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = new_element;
  }

  else
  {
    new_element->next = element->next;
    new_element->prev = element;

    if(element->next == NULL)
    {
      list->tail = new_element;
    }

    else
    {
      element->next->prev = new_element;
    }

    element->next = new_element;
  }

  list->size++;
  return true;
}

bool dlist_remove(d_list *list, d_elem *element, const void **data)
{
  if(element == NULL || dlist_size(list) == 0)
  {
    return false;
  }

  *data = element->data;

  if(element == list->head)
  {
    list->head = element->next;

    if(list->head == NULL)
    {
      list->tail = NULL;
    }

    else
    {
      element->next->prev = NULL;
    }
  }

  else
  {
    element->prev->next = element->next;

    if(element->next = NULL)
    {
      list->tail = element->prev;
    }

    else
    {
      element->next->prev = element->prev;
    }
  }

  free(element);
  list->size--;
  return true;
}
