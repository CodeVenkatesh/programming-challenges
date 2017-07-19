/*
PROBLEM:
	given a k_join board (basically an nxn "table" that stands upright)
	you're given a legal starting position:
		ex/
			LEGAL:
				. . . .
				. . . .
				. B B B
				R R R R
			
			ILLEGAL:
				. . . R
				. B B .
				. . . .			(gravity applies)
				B R B .

	while opponent isn't looking, you rotate the board 90 degrees clockwise
		you can only do this once, because if you do it too many times then opponent will notice

	given a legal starting position, find out who won after rotating it
		(you win if there are k pieces of the same color in a row, column, or diagonal - left or right)
		it is possible for both to win and for neither to win

METHOD:
	store everything as a vector<string>
	notice rotate --> columns = rows
	check if there's k in a row for each case
	display winner
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <sstream>

using namespace std;

//to make life easier
typedef vector<string> vs;

//instead of using char, this is a better approach
//COLOR: either red or blue (R, B)
//WINNER: either red, blue, both, or neither can win (RED, BLUE, NEITHER, BOTH)
enum COLOR { R, B };
enum WINNER { RED, BLUE, NEITHER, BOTH };

/*
k_join class

private variables:
	v, compare, z (vector<string> (vs))
	x (int)

private methods:
	none

public variables:
	none

public methods:
	get_v: (returns v)
	set_v: (sets v to a passed vs)

	init: 
		TASK: populate v to the format given in the problem
		ARGUMENTS: NONE
		RETURN: void

	rotate_gravity:
		TASK: rotate the board by creating a new vs containing each col of the board as the row, and correct it
		ARGUMENTS: NONE
		RETURN: void

	printv:
		TASK: print a vs
		ARGUMENTS: vs
		RETURN: void
	
	gen_col:
		TASK: generate a column given the index
		ARGUMENTS: int
		RETURN: string

	contains:
		TASK: see if a string s contains a char c
		ARGUMENTS: char, string
		RETURN: bool

	correct_board:
		TASK: recursively correct the board until no more corrections can be applied 
			  (corrections meaning while gravity is applied)
		ARGUMENTS: vs
		RETURN: vs

	horizontal:
		TASK: check to see if there's k c's in a row
		ARGUMENTS: vs, int, COLOR
		RETURN: bool

	vertical:
		TASK: check to see if there's k c's in a column
		ARGUMENTS: vs, int, COLOR
		RETURN: bool

	diagonal_l:
		TASK: check to see if there's k c's in a left diagonal
		ARGUMENTS: vs, int, COLOR
		RETURN: bool

	diagonal_r:
		TASK: check to see if there's k c's in a right diagonal
		ARGUMENTS: vs, int, COLOR
		RETURN: bool

	check_board:
		TASK: determine the winner
		ARGUMENTS: NONE
		RETURN: WINNER
*/

class k_join
{
private:
	vs v;
	vs compare, z;
	int x;

public:
	vs get_v() { return this->v; }
	void set_v(vs k) { this->v = k; }

	void init();
	void rotate_gravity();
	string gen_col(vs, int);

	bool contains(char, string);

	vs correct_board(vs);
	void printv(vs);

	bool horizontal(vs, int, COLOR);
	bool vertical(vs, int, COLOR);
	bool diagonal_l(vs, int, COLOR);
	bool diagonal_r(vs, int, COLOR);
	WINNER check_board();

};

bool k_join::contains(char c, string s)
{
	for (string::iterator it = s.begin(); it != s.end(); it++)
		if (*it == c)
			return true;

	return false;
}

void k_join::printv(vs k)
{
	for (vs::iterator it = k.begin(); it != k.end(); it++)
		cout << *it << endl;

	cout << endl;
}

void k_join::init()
{
	int num_lines;
	cin >> num_lines;

	int K;
	cin >> K;
	x = K;

	for (int i = 0; i < num_lines; i++)
	{
		string s;
		for (int j = 0; j < num_lines; j++)
		{
			char c;
			cin >> c;
			s += c;
		}

		v.push_back(s);
	}
}

string k_join::gen_col(vs c, int index)
{
	if (index < 0 || index >= c.size()) throw out_of_range("darn");
	else
	{
		string s;

		for (int i = 0; i < c.size(); i++)
			s += c.at(i).at(index);

		return s;
	}
}

vs k_join::correct_board(vs k)
{
	if (compare == k) return compare;

	else
	{
		compare = k;
		for (int i = k.size() - 1; i >= 1; i--)
		{
			for (int j = 0; j < k.at(i).size(); j++)
			{
				if (k.at(i).at(j) == '.' && k.at(i - 1).at(j) == 'R')
				{
					k.at(i).at(j) = 'R';
					k.at(i - 1).at(j) = '.';
				}

				else if (k.at(i).at(j) == '.' && k.at(i - 1).at(j) == 'B')
				{
					k.at(i).at(j) = 'B';
					k.at(i - 1).at(j) = '.';
				}
			}
		}

		z = k;
		return correct_board(z);
	}
}

void k_join::rotate_gravity()
{
	vs new_v;

	for (int i = 0; i < v.size(); i++)
	{
		string s = gen_col(v, i);
		new_v.push_back(s);
	}

	vs j = correct_board(new_v);

	printv(j);

	set_v(j);
}

bool k_join::horizontal(vs s, int k, COLOR c)
{
	for (int i = 0; i < s.size(); i++)
	{
		string a = s.at(i);

		switch (c)
		{
		case COLOR::R:
			for (int j = 0; j <= a.size() - k; j++)
			{
				string b;
				for (int m = j; m < k + j; m++)
					b += a.at(m);

				if (!contains('B', b) && !contains('.', b))
					return true;
			}

		case COLOR::B:
			for (int j = 0; j <= a.size() - k; j++)
			{
				string b;
				for (int m = j; m < k + j; m++)
					b += a.at(m);

				if (!contains('R', b) && !contains('.', b))
					return true;
			}
		}
	}

	return false;
}

bool k_join::vertical(vs s, int k, COLOR c)
{
	vs ns;
	for (int i = 0; i < s.size(); i++)
	{
		string l = gen_col(s, i);
		ns.push_back(l);
	}

	return horizontal(ns, k, c);
}

bool k_join::diagonal_l(vs s, int k, COLOR c)
{
	vs ns;
	for (int i = s.size() - 1; i >= k - 1; i--)
	{
		for (int j = 0; j <= s.at(i).size() - k; j++)
		{
			string a;
			for (int m = j; m < k + j; m++)
			{
				char ch = s.at(i - m).at(j + m);
				a += ch;
			}

			ns.push_back(a);
		}
	}

	return horizontal(ns, k, c);
}

bool k_join::diagonal_r(vs s, int k, COLOR c)
{
	vs ns;
	for (int i = 0; i <= s.size() - k; i++)
	{
		for (int j = 0; j <= s.at(i).size() - k; j++)
		{
			string a;
			for (int m = j; m < k + j; m++)
			{
				char ch = s.at(i + m).at(j + m);
				a += ch;
			}

			ns.push_back(a);
		}
	}
	return horizontal(ns, k, c);
}

WINNER k_join::check_board()
{
	init();
	rotate_gravity();

	bool r = false, b = false;

	if (horizontal(v, x, COLOR::R) || vertical(v, x, COLOR::R) ||
		diagonal_l(v, x, COLOR::R) || diagonal_r(v, x, COLOR::R)) r = true;

	if (horizontal(v, x, COLOR::B) || vertical(v, x, COLOR::B) ||
		diagonal_l(v, x, COLOR::B) || diagonal_r(v, x, COLOR::B)) b = true;

	cout << "hr: " << horizontal(v, x, COLOR::R) << "\n"
		<< "vr: " << vertical(v, x, COLOR::R) << "\n"
		<< "dlr: " << diagonal_l(v, x, COLOR::R) << "\n"
		<< "drr: " << diagonal_r(v, x, COLOR::R) << endl;

	cout << "hb: " << horizontal(v, x, COLOR::B) << "\n"
		<< "vb: " << vertical(v, x, COLOR::B) << "\n"
		<< "dlb: " << diagonal_l(v, x, COLOR::B) << "\n"
		<< "drb: " << diagonal_r(v, x, COLOR::B) << endl;

	if (r && b) return WINNER::BOTH;
	else if (r && !b) return WINNER::RED;
	else if (!r && b) return WINNER::BLUE;
	else if (!r && !b) return WINNER::NEITHER;
}

int main()
{
	k_join k;

	WINNER w = k.check_board();
	switch (w)
	{
	case RED:
		cout << "red is the winner" << endl;
		break;
	case BLUE:
		cout << "blue is the winner" << endl;
		break;
	case NEITHER:
		cout << "neither player won" << endl;
		break;
	case BOTH:
		cout << "both players won" << endl;
		break;
	}

	system("pause");
	return 0;
}