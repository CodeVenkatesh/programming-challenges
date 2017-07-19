#include <iostream>
using namespace std;

#define QUEUESIZE

typedef struct
{
	int q[QUEUESIZE + 1]; //queue
	int first; //first element position
	int last; //last element position
	int count; //number of elements
} queue;

void init_queue(queue *k)
{
	k->first = 0;
	k->last = QUEUESIZE - 1;
	k->count = 0;
}

void enqueue(queue *k, int x)
{
	if(k->count >= QUEUESIZE) { cout << "queue overflow enqueue x = " << x << endl; }
	else
	{
		k->last = (k->last + 1) % QUEUESIZE;
		k->q[ k->last ] = x;
		k->count += 1;
	}
}

int dequeue(queue *k)
{
	int x;
	if(k->count <= 0) { cout << "empty queue dequeue" << endl; }
	else
	{
		x = k->q[ k->first ];
		k->first = (k->first + 1) % QUEUESIZE;
		k->count -= 1;
	}

	return x;
}

bool empty(queue *k)
{
	if(k->count <= 0) { return true; }
	else 			  { return false; }
}
