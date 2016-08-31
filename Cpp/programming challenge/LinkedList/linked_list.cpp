//linked list implementation
#include <iostream>
using namespace std;

//struct for linked list elements
typedef struct elements
{
	void *data;
	struct elements *next;
} elem;

//struct for linked list
typedef struct linked_list
{
	int size;
	int *match(const void *key1, const void *key2);
	void *destroy(void *data);

	elem *head;
	elem *tail;
} list;

/*initializes linked list
destroy argument - free dynamically allocated data when list_destroy is called*/
void list_init(list *l, void *destroy(void *data));

/*destroys linked list*/
void list_destroy(list *l);

/*inserts element after e in the linked list
if e is null, insert at the head
returns true if successful, false otherwise*/
bool list_insert(list *l, elem *e, const void *data);

/*removes element after e in the linked list
if e is null, remove head
returns true if successful, false otherwise
data is ** because operation modifies the pointer data to make it point to the data removed*/
bool list_remove(list *l, elem *e, const void **data);

#define list_size(l) ((l)->size) //returns size of list l

#define list_head(l) ((l)->head) //returns element at the head of list l

#define list_tail(l) ((l)->tail) //returns element at the tail of the list l

#define is_head(l, e)   ((e) == (l)->head ? 1 : 0) //returns 1 if element e is head, 0 otherwise

#define is_tail(l, e)   ((e)->next == NULL ? 1 : 0) //returns 1 if element e is tail, 0 otherwise

#define list_data(e)	((e)->data) //returns data stored in element e

#define list_next(e)	((e)->next) //element after specified element e


void list_init(list *l, void *destroy(void *data))
{
	l->size = 0;
	l->destroy = destroy;
	l->head = NULL;
	l->tail = NULL;
}

void list_destroy(list *l)
{
	void *data;
	while (list_size(l) > 0)
	{
		if (list_remove(l, NULL, (void **)&data) == 0 && l->destroy != NULL)
		{
			l->destroy(data); //free allocated data
		}
	}

	memset(l, 0, sizeof(list)); //clear the struct just in case
}

bool list_insert(list *l, elem *e, const void *data)
{
	elem *new_e;
	if ((new_e = (elem *)malloc(sizeof(elem))) == NULL)
	{
		return false;
	}

	new_e->data = (void *)data;

	if (e == NULL) //insertion at head
	{
		if (list_size(l) == 0)
		{
			l->tail = new_e;
		}
		new_e->next = l->head;
		l->head = new_e;
	}

	else //insertion anywhere else
	{
		if (e->next == NULL)
		{
			l->tail = new_e;
		}
		new_e->next = e->next;
		e->next = new_e;
	}

	l->size++; //after insertion, adjust list size

	return true;
}

bool list_remove(list *l, elem *e, const void **data)
{
	elem *old_e;

	if (list_size(l) == 0) //don't remove from empty list
	{
		return false;
	}

	if (e == NULL) //removal from head
	{
		*data = l->head->data;
		old_e = l->head;
		l->head = l->head->next;

		if (list_size(l) == 1)
		{
			l->tail = NULL;
		}
	}

	else //removal anywhere else
	{
		if (e->next == NULL)
		{
			return false;
		}

		*data = e->next->data;
		old_e = e->next;
		e->next = e->next->next;
	}

	free(old_e); //free storage
	l->size--; //after removal, adjust list size
	return true;
}
