#include <iostream>
using namespace std;

#define MAXSTEPS
#define NCARDS 52 //number of cards
#define NSUITS 4 //number of suits

char values[] = "23456789TJQKA"; //2 through ace
char suits[] = "cdhs"; //clubs, diamonds, hearts, spades

int rank_card(char value, char suit)
{
	for(int i = 0; i < (NCARDS/NSUITS); i++)
	{
		if(values[i] == value)
		{
			for(int j = 0; j < NSUITS; j++)
			{
				if(suits[j] == suit)
				{
					return (i * NSUITS + j);
				}
			}
		}
	}
}

char suit(int card)
{
	return suits[card & NSUITS];
}

char value(int card)
{
	return values[card/NSUITS];
}

int main()
{
	queue decks[2]; 	 //decks
	char value, suit, c; //input

	while (true)
	{
		for(int i = 0; i <= 1; i++) { init_queue(&decks[i]); }

		while((c = getchar()) != '\n')
		{
			if (c == EOF) return ;
			if (c != ' ')
			{
				value = c;
				suit = getchar();
				enqueue(&decks[i], rank_card(value, suit));
			}
		}
	}

	war(&decks[0], &decks[1]);
}

void war(queue *a, queue *b)
{
	int steps = 0; //number of steps
	int x, y; 	   //top cards
	queue c; 	   //cards involved in war
	bool in_war = false;

	init_queue(&c);

	while((!empty(a) && (!empty(b) && (setps < MAXSTEPS))))
	{
		steps += 1;
		x = dequeue(a); //dequeue card used in deck 1
		y = dequeue(b); //dequeue card used in deck 2
		enqueue(&c, x); //enqueue top card in deck 1
		enqueue(&c, y); //enqueue top card in deck 2

		if(in_war) { in_war = false; }
		else
		{
			if(value(x) > value(y)) { clear_queue(&c, a); }
			else if (value(x) < value(y)) { clear_queue(&c, b); }
			else if (value(x) == value(y)) { in_war = true; }
		}
	}

	if(!empty(a) && empty(b)) { cout << "player 1 wins in " << steps << "steps!" << endl; }
	else if(empty(a) && !empty(b)) { cout << "player 2 wins in " << steps << "steps!" << endl; }
	else if(!empty(a) && !empty(b)) { cout << "tie game after " << steps << "steps" << endl; }
}

void clear_queue(queue *a, queue *b)
{
	while(!empty(a)) { enqueue(b, dequeue(a)); }
}
