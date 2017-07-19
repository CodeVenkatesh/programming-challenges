#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//display which hand wins in a game of poker
//Just a comment

bool less_than(int i, int j) { return (i < j); }

typedef struct
{
	bool operator() (int i, int j) { return (i < j); }
} myobject;

void hands(vector<int> black_num, vector<char> black_suit, vector<int> white_num, vector<char> white_suit)
{
	string hand;
	cin >> hand;

	/*erase whitespaces in string*/
	for(int i = 0; i < hand.size(); i++)
	{
		if(hand[i] == ' ') { hand.erase(hand.begin() + i); }
	}

	/*puts the suits and numbers inputted into the corresponding vectors*/
	for(int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			if(hand[i] == 'A') 		{ black_num.push_back(14); }
			else if(hand[i] == 'K') { black_num.push_back(13); }
			else if(hand[i] == 'Q') { black_num.push_back(12); }
			else if(hand[i] == 'J') { black_num.push_back(11); }
			else if(hand[i] == 'T') { black_num.push_back(10); }
			else 					{ black_num.push_back((int) hand[i]); }
		}

		else 		 				{ black_suit.push_back(hand[i]); }
	}

	sort(black_num.begin(), black_num.end(), myobject);

	for(int j = 10; j < 20; j++)
	{
		if(i % 2 == 0)
		{
			if(hand[i] == 'A') 		{ white_num.push_back(14); }
			else if(hand[i] == 'K') { white_num.push_back(13); }
			else if(hand[i] == 'Q') { white_num.push_back(12); }
			else if(hand[i] == 'J') { white_num.push_back(11); }
			else if(hand[i] == 'T') { white_num.push_back(10); }
			else 					{ white_num.push_back((int) hand[i]); }
		}

		else 		   				{ white_suit.push_back(hand[i]); }
	}

	sort(white_num.begin(), white_num.end(), myobject);

	//note: all four vectors have size of 5
}

int high_card(vector<int> num) { return num[4]; }

int pair(vector<int> num)
{
	int count = 1;
	for(int i = 1; i < 5; i++)
	{
		if(num[i] == num[i - 1])
		{
			return num[i];
			count += 1;
			break;
		}
	}

	if (count == 1) { return 0; }
}

int straight(vector<int> num)
{
	int count_num = 1; //counter to see if all numbers are the same

	int b = num[0];
	for(int j = 1; j < 5; j++)
	{
		if(num[j] == b + 1)
		{
			count_num += 1;
			b += 1;
		}
	}

	if(count_num == num.size()) { return num[4]; }
	else 						{ return 0; }

}

int flush(vector<int> num, vector<char> suit)
{
	int count_suit = 1; //counter to see if all suits are consecutive

	char a = suit[0];
	for(int i = 1; i < 5; i++)
	{

		if(suit[i] == a) { count_suit += 1; }
	}

	if(count_suit == 5) { return high_card(num); }
	else 				{ return 0; }

}

int straight_flush(vector<int> num, vector<char> suit)
{
	if(straight(num) != 0 && flush(num, suit) != 0) { return num[4]; }
	else 											{ return 0; }
}

int four_of_kind(vector<int> num)
{
	int count1 = 1; //counter to see if there are 4 of the same card
	int count2 = 1;

	int x = num[0];
	for(int i = 1; i < 4; i++)
	{
		if(num[i] == x) { count1 += 1; }
	}

	int y = num[1];
	for(int j = 1; j < 5; j++)
	{
		if(num[j] == y) { count2 += 1; }
	}

	if(count1 == 4)       { return x; }
	else if (count2 == 4) { return y; }
	else 				  { return 0; }
}
